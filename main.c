#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "waveformHeader.h"

int main(void){
    FILE *power_data = fopen("C:\\Users\\t2-rennolds\\OneDrive - UWE Bristol\\Attachments\\programing for eng\\tb2\\Project\\power_quality_log.csv","r");
    if (power_data == NULL) {
        printf("File is either empty or not found.\n");
        return 1;
    }else {
        printf("File found.\n");
        struct WaveformSample data1;

        int i = 0;
        while (fgets(data1.bufferVar, sizeof(data1.bufferVar), power_data) != NULL) {
            i = i + 1;
            data1.frequency[i] = data1.bufferVar;
        }
        printf("%s",data1.frequency);
        free(data1.bufferVar);
        fclose(power_data);
        return 0;
    }}