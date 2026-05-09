//
// Created by t2-rennolds on 29/04/2026.
//

#ifndef PROJECT_IO_H
#define PROJECT_IO_H
typedef struct{
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double trd_percent;
}WaveformSample;
#endif //PROJECT_IO_H
