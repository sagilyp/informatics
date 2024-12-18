#include "STAR.h"
#include <stdio.h>
#include <stdlib.h>


void Remove(int **PPmas, int *size_of_mas ){
 	printf("Выберете номер элемента, который Вы хотите удалить:\n");
    ShowMas (PPmas, size_of_mas);
    int del;
    int n = GetInt(&del);
    while(n != 1 || del<0 || del>(*size_of_mas)-1){                                                                                                                                                                                  
         printf("Ошибка!Попробуйте ещё раз:\n");
         int n = GetInt(&del); 
    }
    DeleteMas (PPmas, del, size_of_mas);
    printf("Текущее состояние массива:\n"); 
    ShowMas (PPmas, size_of_mas);
}    
