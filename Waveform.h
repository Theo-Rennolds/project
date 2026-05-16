#ifndef PROJECT_WAVEFORM_H
#define PROJECT_WAVEFORM_H
typedef struct {
    double sum_phase_A;
    double sum_phase_B;
    double sum_phase_C;
    double sum_phase_ARMS;
    double sum_phase_BRMS;
    double sum_phase_CRMS;
    double max_freqA;
    double min_freqA;
    double max_freqB;
    double min_freqB;
    double max_freqC;
    double min_freqC;
    double meanA;
    double meanB;
    double meanC;
    double RMSA;
    double RMSB;
    double RMSC;
} AnalysisResults; //Creates the variables for all of Waveform.c
#endif //PROJECT_WAVEFORM_H
