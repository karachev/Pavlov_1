#include <stdio.h>
#include <stdbool.h>
#include "print2binary.h"
#include "alghoryhm.h"

int main(void)
{
    unsigned  ui_in_number = 0;
    double    d_in_number  = 0.0;

    printf("sizeof(unsigned long int) = %ld \n"
           "sizeof(double) = %ld \n\n"
           "The value of the variable unsigned long int = ",
           sizeof(ui_in_number), sizeof(d_in_number));
    scanf("%u", &ui_in_number);
    print_ui2b(&ui_in_number);

    printf("Algorithm unsigned long int:\n");
    change_state_in_ui(&ui_in_number);
    print_ui2b(&ui_in_number);
    printf("Got unsigned = %u\n", ui_in_number);

    printf("The value of the variable double = ");
    scanf("%lf", &d_in_number);
    print_d2b (&d_in_number);


    printf("Algorithm double:\n");
    change_state_in_d((long*) (&d_in_number));
    print_d2b (&d_in_number);
    printf("Got double = %.14lf\n", d_in_number);

    return 0;
}
