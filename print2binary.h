#ifndef PRINT2BINARY_H
#define PRINT2BINARY_H
#include "convert2binary_functions.h"

void print_ui2b(unsigned* ui_in_number){
    printf("\n------------------------\n"
           "unsigned long int from file:\n");
    print_ui2b_file(ui_in_number);

    printf("\nulint shift:\n");
    print_ui2b_shifts(ui_in_number);
    printf("\n------------------------\n");
}

void print_d2b(double* d_in_number){
    printf("\n------------------------\n"
           "double from file:\n");
    print_d2b_file(d_in_number);

    printf("\ndouble of union:\n");
    print_d2b_union(d_in_number);

    printf("\ndouble of cast:\n");
    print_d2b_cast(*d_in_number);
    printf("\n------------------------\n");
}
#endif // PRINT2BINARY_H
