/*This header file include functions for printing double and unsigned
in standart output (descriptor == 1)*/
#ifndef CONVERT_FUNCTIONS_H
#define CONVERT_FUNCTIONS_H
#include <stdio.h>  //
#include <limits.h> //CharBit

//For work with Double
void print_d2b_file(double* in_num){
    FILE   *p_file;
    size_t num_size = sizeof(*in_num);

    if ((p_file = fopen("tmp_double.txt", "w+")) == NULL){
        printf("Error opening file");
        exit(1);
    }

    fwrite(in_num, 1,num_size, p_file); //Записываем массив в блок памяти

    size_t j;
    for (j = 0; j < num_size; ++j){
        char   c_buffer = "";
        fseek(p_file, -1-j, SEEK_END); //Управление указателя в потоке
        fread(&c_buffer, 1, 1, p_file); //Считывает массив

        int i;
        for (i = CHAR_BIT - 1; i >= 0; --i){
            printf("%d", ((c_buffer >> i) & 1)); //сдвигаем побитовое И и записывает в p_file
        }
        printf(" ");
    }

    fclose(p_file);
    remove("tmp_double.txt");
}

void print_d2b_union(double* in_num){//WORK
    union
        {
            double as_double;
            long   as_long;
        } data;
    data.as_double = *in_num;
    int i;
    for (i = sizeof(long) * CHAR_BIT - 1; i >= 0; --i){
        printf("%d", ((data.as_long >> i) & 1));
        if (!(i % CHAR_BIT) && i != 0) printf(" "); //char_bit побитовое чтение
    }
}

void print_d2b_cast(double in_num){//WORK
    long* p_tmp = (long*) (&in_num);
    int i;
    for (i = sizeof(long) * CHAR_BIT - 1; i >= 0; --i){
        printf("%d", ((*p_tmp >> i) & 1));
        if (!(i % CHAR_BIT) && i != 0) printf(" ");
    }
}

//For work with unsigned int
void print_ui2b_file(unsigned* in_num){
    FILE   *p_file;
    size_t num_size = sizeof(*in_num);

    if ((p_file = fopen("tmp_uint.txt", "w+")) == NULL){ //создает файл для чтения записи (по умолчанию текстовый)
        printf("Error opening file");
        exit(1);
    }

    fwrite(in_num, 1,num_size, p_file); //Записывает массив в блок памяти

    size_t j;
    for (j = 0; j < num_size; ++j){
        char   c_buffer = "";
        fseek(p_file, -1-j, SEEK_END); // Управляет указателем в потоке
        fread(&c_buffer, 1, 1, p_file); // Считывает файл

        int i;
        for (i = CHAR_BIT - 1; i >= 0; --i){
            printf("%d", ((c_buffer >> i) & 1)); //Записывает в .txt файл
        }
        printf(" ");
    }

    fclose(p_file);
    remove("tmp_uint.txt");
}

void print_ui2b_shifts(unsigned* in_num){ //WORK
    int i;
    for (i = sizeof(unsigned) * CHAR_BIT - 1; i >= 0; --i){
        printf("%d", ((*in_num >> i) & 1));
        if (!(i % CHAR_BIT) && i != 0) printf(" ");
    }
}
#endif // CONVERT_FUNCTIONS_H
