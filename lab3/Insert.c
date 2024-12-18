#include "STAR.h"
#include <stdio.h>
#include <stdlib.h>



void Insert(int **PPmas, int *size_of_mas){
    printf("Выберете номер места, куда Вы хотите вставить элемент:\n "); 
    ShowMas (PPmas, size_of_mas);
    int vst, zvst, delta;
    while(GetInt(&vst) != 1 || vst<0 ){
    	 printf("Ошибка!Попробуйте ещё раз:\n");
    }
    (*size_of_mas)++;
    if(vst > (*size_of_mas)-2){
    	vst = (*size_of_mas) - 1;	
    }
    *PPmas = (int *) realloc (*PPmas, sizeof (int) * *size_of_mas);
    if (*PPmas == NULL){
    	exit(2);
    }
    delta = *size_of_mas - vst;
    for (int i = 1; i < delta; i++){
	   int *hoh;
	   hoh = *PPmas + vst + i;
	   *(hoh) = *(hoh - 1);
      } 
    printf("Введите значение элемента, которое Вы хотите вставить:\n");
    while(GetInt(&zvst) != 1){                                                                                                                                                                                  
       printf("Ошибка!Попробуйте ещё раз:\n"); 
     }
    (*PPmas)[vst] = zvst;
    printf("Текущее состояние массива:\n");
    ShowMas (PPmas, size_of_mas);
}    
