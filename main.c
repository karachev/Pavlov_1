#include <stdio.h>
#include <stdbool.h>
#include "print2binary.h"
#include "alghoryhm.h"


int main(void)
{
    unsigned  ui_in_number = 0;
    double    d_in_number  = 0.0;

    printf("sizeof(unsigned int) = %ld \n"
           "sizeof(double) = %ld \n\n"
           "Значение переменной unsigned int = ",
           sizeof(ui_in_number), sizeof(d_in_number));
    scanf("%u", &ui_in_number);

    printf("Значение переменной double = ");
    scanf("%lf", &d_in_number);

    print_ui2b(&ui_in_number);
    print_d2b (&d_in_number);

    printf("Алгоритм с unsigned int:\n");
    change_state_in_ui(&ui_in_number);
    print_ui2b(&ui_in_number);
    printf("Получили unsigned = %u\n", ui_in_number);

    printf("Алгоритм с double:\n");
    change_state_in_d((long*) (&d_in_number));
    print_d2b (&d_in_number);
    printf("Получили double = %.14lf\n", d_in_number);

    return 0;
}
