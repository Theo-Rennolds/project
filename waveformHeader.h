//
// Created by t2-rennolds on 28/04/2026.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef PROJECT_WAVEFORMHEADER_H
#define PROJECT_WAVEFORMHEADER_H

struct WaveformSample {
    char timestamp[100];
    char phase_A_voltage[100];
    char phase_B_voltage[100];
    char phase_C_voltage[100];
    char line_current[100];
    char frequency[100];
    char power_factor[100];
    char trd_percent[100];
};
#endif //PROJECT_WAVEFORMHEADER_H
