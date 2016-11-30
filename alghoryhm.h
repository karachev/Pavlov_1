#ifndef ALGHORYHM_H
#define ALGHORYHM_H
#include <limits.h> //CharBit

void change_state_in_ui(unsigned* ui_in_number){
    int bits_state = 0;
    unsigned short user_lsb = 0;
    unsigned short user_range = 0;
    unsigned short unsigned_size_of_bits =  sizeof(unsigned) * CHAR_BIT;

    printf("\nВведите в формате:\n"
           "состояние [0,1], номер младшего бита [0-31], количество рядом стоящих бит [0-31]\n");
    scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    while ((user_lsb + 1) + user_range > unsigned_size_of_bits){
        printf("Ошибка ввода, введите корректные значения, совпадающие с размерами unsigned (4 Байта):\n");
        scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    }
    if(!(user_lsb || user_range)) return;

    unsigned mask = ~0;
    mask <<= (unsigned_size_of_bits - (user_lsb + user_range)); //0 border in left
    mask >>= (unsigned_size_of_bits - (user_lsb + user_range));

    mask >>= user_lsb; //0 border in right
    mask <<= user_lsb;

    *ui_in_number = (bits_state) ? (*ui_in_number) | mask :
                                   (*ui_in_number) & (~mask);
}

void change_state_in_d(long* d_in_number){
    int bits_state = 0;
    unsigned short user_lsb = 0;
    unsigned short user_range = 0;
    unsigned short double_size_of_bits =  sizeof(long) * CHAR_BIT;

    printf("\nВведите в формате:\n"
           "состояние [0,1], номер младшего бита [0-63], количество рядом стоящих бит [0-63]\n");
    scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    while ((user_lsb + 1) + user_range > double_size_of_bits){
        printf("Ошибка ввода, введите корректные значения, совпадающие с размерами unsigned (4 Байта):\n");
        scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    }
    if(!(user_lsb || user_range)) return;

    unsigned long mask = ~0;
    mask <<= (double_size_of_bits - (user_lsb + user_range)); //0 border in left
    mask >>= (double_size_of_bits - (user_lsb + user_range));

    mask >>= user_lsb; //0 border in right
    mask <<= user_lsb;

    *d_in_number = (bits_state) ? (*d_in_number)  |  mask :
                                   (*d_in_number) & (~mask);
}
#endif // ALGHORYHM_H
