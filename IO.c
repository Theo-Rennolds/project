#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"

extern void analysis(const WaveformSample* dataP,int count);

int file_input(const char* file_name){ ///File is sent to here
    FILE *power_data = fopen(file_name, "r");
    if (power_data == NULL){ ///Checks for if the file is empty
        return 1;
    }
    printf("File opened successfully.\n");
    int file_height = 0; ///How 'tall' (how many lines) are in the file
    char line[4096];
    while (fgets(line,sizeof(line),power_data) != NULL) {
        file_height=file_height+1;
    }
    rewind(power_data); ///Returns back to the top of the CSV file
    WaveformSample *dataP = malloc(file_height * sizeof(WaveformSample)); ///Storage with flexable allocation according to file 'height'
    int i = 0;
    int successful_reads = 0;
    while (i<file_height&&fgets(line,sizeof(line),power_data) != NULL){
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
        i=i+1; ///Whole statement used to apply the data found in the CSV file to their respective arrays
    }
    free(dataP);
    fclose(power_data);
    analysis(dataP,successful_reads);
    return 0;
}