#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"

int file_input(const char* file_name){
    FILE *power_data = fopen(file_name, "r");
    if (power_data == NULL){
        printf("ERROR: Could not open file.\n");
        return 1;
    }
    printf("File opened successfully.\n");
    int file_height = 0;
    char line[1024];
    while (fgets(line, sizeof(line), power_data) != NULL) {
        file_height=file_height+1;
    }
    printf("Total lines counted: %d. \n", file_height);
    if (file_height == 0) {
        printf("Error: File is empty. \n");
        fclose(power_data);
        return 1;
    }
    rewind(power_data);
    WaveformSample *data = malloc(file_height * sizeof(WaveformSample));
    if (data == NULL) {
        printf("Memory allocation failed. \n");
        fclose(power_data);
        return 1;
    }
    free(data);
    fclose(power_data);
    return 0;
}