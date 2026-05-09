#include <stdio.h>
#include <math.h>
#include "IO.h"
#include "Waveform.h"

double square_number(double num);

void analysis(const WaveformSample *dataP, const int count){
    remove("results.txt"); //Clears any file that was used previously for new results
    FILE *output_file = fopen("results.txt","a"); //Creates and appends items to txt file
    if (output_file == NULL) {
        printf("Could not open or create FileOutput.txt\n");
        return;
    }
    AnalysisResults result = {0};
    for (int i=0;i<count;i=i+1){
        result.sum_phase_A = result.sum_phase_A+dataP[i].phase_A_voltage;
        result.sum_phase_B = result.sum_phase_B+dataP[i].phase_B_voltage;
        result.sum_phase_C = result.sum_phase_C+dataP[i].phase_C_voltage; //The summation of A, B and C
        result.sum_phase_ARMS = result.sum_phase_ARMS+square_number(dataP[i].phase_A_voltage);
        result.sum_phase_BRMS = result.sum_phase_BRMS+square_number(dataP[i].phase_B_voltage);
        result.sum_phase_CRMS = result.sum_phase_CRMS+square_number(dataP[i].phase_C_voltage); //The summation of the squares of A, B and C
        if (fabs(dataP[i].phase_A_voltage) >= 324.9){
            fprintf(output_file,"sample number %d in Phase A has been flagged for clipping.\n",i+1);
        }
        if (fabs(dataP[i].phase_B_voltage) >= 324.9){
            fprintf(output_file,"sample number %d in Phase B has been flagged for clipping.\n",i+1);
        }
        if (fabs(dataP[i].phase_C_voltage) >= 324.9){
            fprintf(output_file,"sample number %d in Phase C has been flagged for clipping.\n",i+1); //Flags sample numbers
        }
        if (dataP[i].phase_A_voltage >= result.max_freqA) {
            result.max_freqA = dataP[i].phase_A_voltage;
        }
        if (dataP[i].phase_B_voltage >= result.max_freqB) {
            result.max_freqB = dataP[i].phase_B_voltage;
        }
        if (dataP[i].phase_C_voltage >= result.max_freqC) {
            result.max_freqC = dataP[i].phase_C_voltage;
        }
        if (dataP[i].phase_A_voltage <= result.min_freqA) {
            result.min_freqA = dataP[i].phase_A_voltage;
        }
        if (dataP[i].phase_B_voltage <= result.min_freqB) {
            result.min_freqB = dataP[i].phase_B_voltage;
        }
        if (dataP[i].phase_C_voltage <= result.min_freqC) {
            result.min_freqC = dataP[i].phase_C_voltage; //The logistics for Min/Max A, B and C
        }
    }
    result.RMSA = sqrt(result.sum_phase_ARMS / count);
    result.RMSB = sqrt(result.sum_phase_BRMS / count);
    result.RMSC = sqrt(result.sum_phase_CRMS / count); //The RMS of A, B and C
    result.meanA = result.sum_phase_A/count;
    result.meanB = result.sum_phase_B/count;
    result.meanC = result.sum_phase_C/count; //The Mean of A, B and C
    if (result.RMSA >= 230-(230/10)||result.RMSA >= 230+(230/10)) {
        fprintf(output_file,"Phase A is within 10 percent of 230\n");
    }
    if (result.RMSB >= 230-(230/10)||result.RMSB >= 230+(230/10)) {
        fprintf(output_file,"Phase B is within 10 percent of 230\n");
    }
    if (result.RMSC >= 230-(230/10)||result.RMSC >= 230+(230/10)) {
        fprintf(output_file,"Phase C is within 10 percent of 230\n"); //The clipping detection
    }
    fprintf(output_file,"RMS Phase A Voltage: %.8f V\n", result.RMSA);
    fprintf(output_file,"RMS Phase B Voltage: %.8f V\n", result.RMSB);
    fprintf(output_file,"RMS Phase C Voltage; %.8f V\n", result.RMSC);
    fprintf(output_file,"Max Voltage for Phase A: %.8f V\n", result.max_freqA);
    fprintf(output_file,"Min Voltage for Phase A: %.8f V\n", result.min_freqA);
    fprintf(output_file,"Max Voltage for Phase B: %.8f V\n", result.max_freqB);
    fprintf(output_file,"Min Voltage for Phase B: %.8f V\n", result.min_freqB);
    fprintf(output_file,"Max Voltage for Phase C: %.8f V\n", result.max_freqC);
    fprintf(output_file,"Min Voltage for Phase C: %.8f V\n", result.min_freqC);
    fprintf(output_file,"Mean Phase A Voltage: %.8f V\n", result.meanA);
    fprintf(output_file,"Mean Phase B Voltage: %.8f V\n", result.meanB);
    fprintf(output_file,"Mean Phase C Voltage: %.8f V\n", result.meanC); //Appending the maths done to the txt file.
    fclose(output_file); ///Closes file
}
double square_number(const double num) {
    const double val = num * num;
    return val; //Custom function to square a number
}