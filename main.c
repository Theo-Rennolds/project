#include <stdio.h>

int file_input(const char* file_name);
int analysis(float* result);

int main(void)
{
    // You can change the path here if needed
    const int result = file_input("C:\\Users\\theor\\OneDrive - UWE Bristol\\Attachments\\programing for eng\\tb2\\Project\\power_quality_log.csv");
    return result;
}