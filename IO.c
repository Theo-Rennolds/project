#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"

extern void analysis(const WaveformSample* dataP,int count);

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
    fgets(line, sizeof(line), power_data);
    WaveformSample *dataP = malloc(file_height * sizeof(WaveformSample));
    if (dataP == NULL) {
        printf("Memory allocation failed. \n");
        fclose(power_data);
        return 1;
    }
    printf("Memory allocation successful. \n");
    int i = 0;
    int successful_reads = 0;
    while (i < file_height && fgets(line, sizeof(line), power_data) != NULL){
        line[strcspn(line, "\n\r")] = 0;
        int fields = sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                            &dataP[i].timestamp,
                            &dataP[i].phase_A_voltage,
                            &dataP[i].phase_B_voltage,
                            &dataP[i].phase_C_voltage,
                            &dataP[i].line_current,
                            &dataP[i].frequency,
                            &dataP[i].power_factor,
                            &dataP[i].trd_percent);
        if (fields == 8)successful_reads=successful_reads+1;
        i=i+1;
    }
    fclose(power_data);
    analysis(dataP,successful_reads);
    return 0;
}