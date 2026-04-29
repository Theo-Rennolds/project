//
// Created by t2-rennolds on 28/04/2026.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef PROJECT_WAVEFORMHEADER_H
#define PROJECT_WAVEFORMHEADER_H
struct WaveformSample {
    char bufferVar[1000];
    char timestamp[1000];
    char phase_A_voltage[1000];
    char phase_B_voltage[1000];
    char phase_C_voltage[1000];
    char line_current[1000];
    char frequency[1000];
    char power_factor[1000];
    char trd_percent[1000];
};
#endif //PROJECT_WAVEFORMHEADER_H
