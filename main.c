#include <stdio.h>

int file_input(const char* file_name);
int analysis(float* result);
int main(int argc, char *argv[]){ //Allows for running through commandline
    const char* filename = NULL;
    if (argc > 1) {
        filename = argv[1];
        printf("Using file: %s\n", filename);
    }else{
        printf("No filename provided.\n");
    }
    const int result = file_input(filename);
    return result;
}