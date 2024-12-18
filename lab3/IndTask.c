#include <stdio.h>
#include <stdlib.h>
#include "STAR.h"


void IndTask(int **PPmas,int **Parr, int *size_of_mas){
    int cnt = 0, num = 0, k = 0;
    int *p = &num;
    for (int i = 0; i < (*size_of_mas)-1; i++){
      if (i == (*size_of_mas)-2 && ((*PPmas)[i] == (*PPmas)[i + 1])){
      		cnt += 2;
      		*Parr = (int*)realloc(*Parr, sizeof(int)*cnt);
      		if( *Parr == NULL){
      			exit(2);
      		}
      		(*Parr)[num] = (*PPmas)[i];
      		num++;
      		(*Parr)[num] = (*PPmas)[i+1];
      		num++;
      		DeleteMas(PPmas,i,size_of_mas);
      		i--;
      		DeleteMas(PPmas, i+1, size_of_mas);
      		k = 1;
      }
      else if(i == (*size_of_mas)-2 && ((*PPmas)[i+1] != (*PPmas)[i + 2])){
      		k = 1;
      }
	  else if ((*PPmas)[i] == (*PPmas)[i + 1] && ((*PPmas)[i + 1] != (*PPmas)[i + 2]) && k == 0){   
    	  cnt += 2;
	      *Parr = (int*)realloc(*Parr, sizeof(int)*cnt);
	      if (*Parr == NULL){
	      	exit(2);
	      }
          (*Parr)[num] = (*PPmas)[i];
          num++;
          (*Parr)[num] = (*PPmas)[i+1];
          num++;
          DeleteMas(PPmas,i,size_of_mas);
          i--; 
          DeleteMas(PPmas, i+1, size_of_mas);
	    }
	  else if(((*PPmas)[i] == (*PPmas)[i + 1]) && k == 0){
	      cnt++;
	      *Parr = (int*)realloc(*Parr,sizeof(int)*cnt);
	      if (*Parr == NULL){
	      	exit(2);
	      }
	      (*Parr)[num] = (*PPmas)[i];
	      num++; 
	      DeleteMas(PPmas,i,size_of_mas);
	      i--;
	      }
	}  
    printf("Текущее состояние исходного массива:\n");
	ShowMas(PPmas, size_of_mas);
	printf("[][][][][][][][][][][][][][][][][][][][]\n");
	printf("Состояние нового массива:\n ");
	ShowMas(Parr, p);
	    
     
} 
