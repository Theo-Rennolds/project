#include <stdio.h>
#include <stdlib.h>
#include "waveformHeader.h"

int main(void){
    FILE *power_data = fopen("C:\\Users\\t2-rennolds\\OneDrive - UWE Bristol\\Attachments\\programing for eng\\tb2\\Project\\power_quality_log.csv","r");
    if (power_data == NULL) {
        printf("File is either empty or not found. \n");
        return 1;
    }else{
        printf("file found\n");
    }
    struct WaveformSample data1;
    int i = 0;
    while (fgets(data1.timestamp,sizeof(data1.timestamp),power_data)!=NULL) {
        if (i%8==0){
            data1.timestamp[i] = "test";
        }
    }
    fclose(power_data);
    return 0;

}