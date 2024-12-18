#include "STAR.h"
#include <stdio.h>


void Replace(int **PPmas, int *size_of_mas){
    printf("Выберете номер элемента, который Вы хотите заменить:\n");
    ShowMas(PPmas, size_of_mas);
    int men, zmen;
    int a, za;
    a = GetInt(&men);
    while(a != 1 || men < 0 || men > (*size_of_mas) -1){                                                                                                                                                                                 
        printf("Ошибка!Попробуйте ещё раз:\n"); 
        a = GetInt(&men);
    }
    printf("Введите значение элемента, которое Вы хотите заменить:\n"); 
    za = GetInt(&men);
    while(za != 1){                                                                                                                                                                                  
        printf("Ошибка!Попробуйте ещё раз:\n");
        za = GetInt(&men); 
    }
    (*PPmas)[men] = zmen;
    printf("Текущее состояние массива:\n"); 
    ShowMas (PPmas, size_of_mas);
}    
