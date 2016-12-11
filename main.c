#include <stdio.h>
#include <stdbool.h>
#include "print2binary.h"
#include "alghoryhm.h"
#include <Windows.h>// Обязательное подключение файла


enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

int main(void)
{
    int numBg;
    int numCol;
    /*Получение дескриптора*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//    Атрибуты цветов задаются в виде ДВУХ шестнадцатеричных цифр — первая
//    задает цвет фона, а вторая определяет цвет переднего плана. Каждая цифра
//    может иметь следующие значения:

//     0 = Черный 8 = Серый
//     1 = Синий 9 = Светло-синий
//     2 = Зеленый A = Светло-зеленый
//     3 = Голубой B = Светло-голубой
//     4 = Красный C = Светло-красный
//     5 = Лиловый D = Светло-лиловый
//     6 = Желтый E = Светло-желтый
//     7 = Белый F = Ярко-белый

    system("color 80");

    printf("Black = 0 \n"
           "Blue = 1 \n"
           "Green = 2 \n"
           "Cyan = 3 \n"
           "Red = 4 \n"
           "Magenta = 5 \n"
           "LightGray = 7 \n"
           "DarkGray = 8 \n"
           "LightBlue = 9 \n"
           "LightGreen = 10 \n"
           "LightCyan = 11 \n"
           "LightRed = 12 \n"
           "LightMagenta = 13 \n"
           "Yellow = 14 \n"
           "White = 15 \n"
           "------------------------\n");

    printf("Enter the background color ");
    scanf("%u", &numBg);

    printf("Enter the text color ");
    scanf("%u", &numCol);

    SetConsoleTextAttribute(hConsole, (WORD) ((numBg << 4) | numCol));

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
