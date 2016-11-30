#ifndef PRINT2BINARY_H
#define PRINT2BINARY_H
#include "convert2binary_functions.h"

void print_ui2b(unsigned* ui_in_number){
    printf("\n=================\n"
           "uint из файла:\n");
    print_ui2b_file(ui_in_number);

    printf("\nuint сдвигами:\n");
    print_ui2b_shifts(ui_in_number);
    printf("\n=================\n");
}

void print_d2b(double* d_in_number){
    printf("\n=================\n"
           "double из файла:\n");
    print_d2b_file(d_in_number);

    printf("\ndouble из union:\n");
    print_d2b_union(d_in_number);

    printf("\ndouble из cast:\n");
    print_d2b_cast(*d_in_number);
    printf("\n=================\n");
}
#endif // PRINT2BINARY_H
