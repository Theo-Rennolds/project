#include <stdio.h>

int main(void){
    FILE *power_data = fopen("","r");
    if (power_data == NULL){
        printf("File is either empty or not found. \n");
        return 1;
    }
    char timestamp[100];
    char phase_A_voltage[100];
    char phase_B_voltage[100];
    char phase_C_voltage[100];
    char line_current[100];
    char frequency[100];
    char power_factor[100];
    char trd_percent[100];

    while (fscanf(power_data,"%lf %lf %lf %lf %lf %lf %lf %lf",&timestamp,
                  &phase_A_voltage,&phase_B_voltage,&phase_C_voltage,
                  &line_current,frequency,power_factor,trd_percent) == 8) {
        printf("time stamp: %lf", timestamp);
    }

    fclose(power_data);
    return 0;
}