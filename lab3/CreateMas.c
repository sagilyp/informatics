#include <stdio.h>
#include <stdlib.h>
#include "STAR.h"

void CreateMas(int **PPmas, int size_of_mas){                                 
    *PPmas = (int *)calloc(size_of_mas, sizeof(int));
    if(*PPmas == NULL){
     	printf("Ошибка!\n");
    	exit(2);
    }
    for(int i=0; i<size_of_mas; i++){                                                                                                   
        printf("Введите %d элемент:\n", i);
        while(GetInt((*PPmas) + i) != 1){                                                                                                                                                                                  
            printf("Ошибка!Попробуйте ещё раз:\n"); 
        }                                                                                                                                                                                                       
    }
}    
