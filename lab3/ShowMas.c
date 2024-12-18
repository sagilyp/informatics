#include <stdio.h>
#include <stdlib.h>

void ShowMas(int **a, int *b){                                                                                                                  
    for (int j=0; j<(*b); j++){
        printf(" %d элемент: %d\n", j, *(*a + j));
    }    
}
