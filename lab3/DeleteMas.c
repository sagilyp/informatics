#include <stdio.h>
#include <stdlib.h>

void DeleteMas(int **PPtr, int d, int *b){                                                                                   
    for(int i = d; i < (*b)-1; i++){                                                                                                             
        *((*PPtr) + i) = *((*PPtr) + i + 1);                                                                                                          
    }                                                                                                                                        
    (*b)--;                                                                                                                                  
    *PPtr = (int *)realloc(*PPtr, sizeof(int) * (*b));                                                                                       
}                                                                                                                            
                                                                                                                      
                                                                                                                                                                                                                                                                                                                                                                              
                                                                                                                               

