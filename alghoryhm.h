#ifndef ALGHORYHM_H
#define ALGHORYHM_H
#include <limits.h> //CharBit

void change_state_in_ui(unsigned* ui_in_number){
    int bits_state = 0;
    unsigned short user_lsb = 0;
    unsigned short user_range = 0;
    unsigned short unsigned_size_of_bits =  sizeof(unsigned) * CHAR_BIT;

    printf("\nEnter in the format: \n"
           "the state [0.1], the highest bit number [0-31], close near the number of bits [0-31]\n");

    scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    while ((user_lsb + 1) + user_range > unsigned_size_of_bits){
        printf("Invalid input, enter the correct values ??coinciding with unsigned sizes (4 bytes):\n");
        scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    }
    if(!(user_lsb || user_range)) return;

    unsigned mask = ~0;

    mask <<= (unsigned_size_of_bits - user_lsb);
    mask >>= (unsigned_size_of_bits - user_range);
    mask <<= (user_range -1);

    *ui_in_number = (bits_state) ? (*ui_in_number) | mask :
                                   (*ui_in_number) & (~mask);
}

void change_state_in_d(long* d_in_number){
    int bits_state = 0;
    unsigned short user_lsb = 0;
    unsigned short user_range = 0;
    unsigned short double_size_of_bits =  sizeof(long) * CHAR_BIT;

    printf("\nEnter in the format: \n"
           "the state [0.1], the highest bit number [0-63], close near the number of bits [0-63]\n");
    scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    while ((user_lsb + 1) + user_range > double_size_of_bits){
        printf("Invalid input, enter the correct values ??coinciding with unsigned sizes (4 bytes):\n");
        scanf("%d %hu %hu", &bits_state, &user_lsb, &user_range);
    }
    if(!(user_lsb || user_range)) return;

    unsigned long mask = ~0;

    mask <<= (double_size_of_bits - user_lsb);
    mask >>= (double_size_of_bits - user_range);
    mask <<= (user_range -1);

    *d_in_number = (bits_state) ? (*d_in_number)  |  mask :
                                   (*d_in_number) & (~mask);
}
#endif // ALGHORYHM_H
