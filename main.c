#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "waveformHeader.h"

int main(){
    FILE *power_data = fopen("C:\\Users\\t2-rennolds\\OneDrive - UWE Bristol\\Attachments\\programing for eng\\tb2\\Project\\power_quality_log.csv","r");
    if (power_data == NULL) {
        printf("File is either empty or not found.\n");
        return 1;
    }else{
        printf("File found.\n");
        struct WaveformSample data1;
        int *bufferVar = (int*)malloc(ftell(power_data));
        int i = 0;
        while (fgets((char *) bufferVar, sizeof(bufferVar), power_data) != NULL) {
            char *token;
            token = strtok((char *) bufferVar, ",");
            data1.timestamp[i] = atof(token);
        }
        printf(data1.timestamp);
    fclose(power_data);
    return 0;
    }


}