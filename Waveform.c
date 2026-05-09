//
// Created by theor.
//
#include <stdio.h>
#include <math.h>
#include "IO.h"

double square_number(double num);

void analysis(const WaveformSample *data, const int count){
    FILE *output_file = fopen("FileOutput.txt","a");
    if (data == NULL || count == 0){
        printf("No data to analyze.\n");
        return;
    }
    double sum_phase_A = 0.0;
    double sum_phase_B = 0.0;
    double sum_phase_C = 0.0;
    double sum_phase_ARMS = 0.0;
    double sum_phase_BRMS = 0.0;
    double sum_phase_CRMS = 0.0;
    double max_freq = 0.0;
    double min_freq = 0.0;
    double meanA = 0.0;
    double meanB = 0.0;
    double meanC = 0.0;
    double RMSA = 0.0;
    double RMSB = 0.0;
    double RMSC = 0.0;
    for (int i=0;i<count;i=i+1){
        sum_phase_A = sum_phase_A+data[i].phase_A_voltage;
        sum_phase_B = sum_phase_B+data[i].phase_B_voltage;
        sum_phase_C = sum_phase_C+data[i].phase_C_voltage;
        sum_phase_ARMS = sum_phase_ARMS+square_number(data[i].phase_A_voltage);
        sum_phase_BRMS = sum_phase_BRMS+square_number(data[i].phase_B_voltage);
        sum_phase_CRMS = sum_phase_CRMS+square_number(data[i].phase_C_voltage);
        RMSA = sqrt(sum_phase_ARMS / count);
        RMSB = sqrt(sum_phase_BRMS / count);
        RMSC = sqrt(sum_phase_CRMS / count);
        meanA = sum_phase_A/count;
        meanB = sum_phase_B/count;
        meanC = sum_phase_C/count;
        if (fabs(data[i].phase_A_voltage) >= 324.9){
            fprintf(output_file,"sample number %d in Phase A has been flagged.\n",i+1);
        }
        if (fabs(data[i].phase_B_voltage) >= 324.9){
            fprintf(output_file,"sample number %d in Phase B has been flagged.\n",i+1);
        }
        if (fabs(data[i].phase_C_voltage) >= 324.9){
            fprintf(output_file,"sample number %d in Phase C has been flagged.\n",i+1);
        }
        if (data[i].phase_A_voltage >= max_freq) {
            max_freq = data[i].phase_A_voltage;
        }
        if (data[i].phase_B_voltage >= max_freq) {
            max_freq = data[i].phase_B_voltage;
        }
        if (data[i].phase_C_voltage >= max_freq) {
            max_freq = data[i].phase_C_voltage;
        }
        if (data[i].phase_A_voltage >= min_freq) {
            min_freq = data[i].phase_A_voltage;
        }
        if (data[i].phase_B_voltage >= min_freq) {
            min_freq = data[i].phase_B_voltage;
        }
        if (data[i].phase_C_voltage >= min_freq) {
            min_freq = data[i].phase_C_voltage;
        }
    }
    if (RMSA >= 230-(230/10)||RMSA >= 230+(230/10)) {
        fprintf(output_file,"Phase A is within 10 percent of 230\n");
    }
    if (RMSB >= 230-(230/10)||RMSB >= 230+(230/10)) {
        fprintf(output_file,"Phase B is within 10 percent of 230\n");
    }
    if (RMSC >= 230-(230/10)||RMSC >= 230+(230/10)) {
        fprintf(output_file,"Phase C is within 10 percent of 230\n");
    }
    fprintf(output_file,"RMS Phase A Voltage : %.8f V\n", RMSA);
    fprintf(output_file,"RMS Phase B Voltage : %.8f V\n", RMSB);
    fprintf(output_file,"RMS Phase C Voltage : %.8f V\n", RMSC);
    fprintf(output_file,"Mean Phase A Voltage : %.8f V\n", meanA);
    fprintf(output_file,"Mean Phase B Voltage : %.8f V\n", meanB);
    fprintf(output_file,"Mean Phase C Voltage : %.8f V\n", meanC);
    fclose(output_file);
}
double square_number(const double num) {
    const double val = num * num;
    return val;
}