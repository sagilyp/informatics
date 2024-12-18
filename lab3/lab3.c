#include <stdio.h>
#include <stdlib.h>
#include "STAR.h"

int main()
{   
    int *Pmas=NULL, *Parr=NULL;
    int size_of_mas;
    printf("Если Вы хотите создать массив, нажмите 1.\n");
    printf("Если Вы хотите закончить работу программы, нажмите 0.\n");
    char ch1 = getchar();
    while((ch1 != '0') &&  (ch1 != '1')){
    	printf("Ошибка! Вы ввели неправильное число. Попробуйте снова.\n");
     	while(getchar()!='\n');
     	ch1 = getchar();
     	}
  	
  	if(ch1 == '1'){
  		printf("Введите размер массива:\n");
  		scanf("%d", &size_of_mas); 	   
   	    CreateMas(&Pmas, size_of_mas);
        ShowMas(&Pmas, &size_of_mas);
    }   
 
    else{
        printf("До свидания!\n");
        exit(3);
    }
    //char ch2 ;
    while(ch1 != '0'){
        printf("Если Вы хотите заменить элемент массива, нажмите 1.\n");                                                                         
        printf("Если Вы хотите вставить элемент массива по его номеру, нажмите 2.\n");
        printf("Если Вы хотите удалить элемент массива, нажмите 3\n");
        printf("Если Вы хотите найти группы подряд стоящих одинаковых чисел и создать из них новую последовательность, нажмите 4.\n");
        printf("Если Вы хотите создать новый массив, нажмите 5.\n");
        printf("Если Вы хотите вывести состояние текущего массива на экран, нажмите 6.\n");
        printf("Если Вы хотите закончить работу программы, нажмите 0.\n");
        while(getchar()!='\n');
        ch1 = getchar();
    	while(ch1 != '0' && ch1 != '1' && ch1 != '2' && ch1 != '3' && ch1 != '4' && ch1 != '5' && ch1 != '6'){
    		printf("Ошибка! Вы ввели неправильное число. Попробуйте снова.\n");
    		while(getchar()!='\n');
    		ch1 = getchar();
    		}
    	if(ch1 == '1'){
    		Replace(&Pmas, &size_of_mas);
    	}	
    	if(ch1 == '2'){
    		Insert(&Pmas, &size_of_mas);
    	}
    	if(ch1 == '3'){
    		Remove(&Pmas, &size_of_mas);
    	}
    	if(ch1 == '4'){
    		IndTask(&Pmas,&Parr,&size_of_mas);
    	}
    	if(ch1 == '5'){
    		free(Pmas);
    		Pmas = NULL;
    		printf("Введите размер массива:\n");
    		scanf("%d", &size_of_mas);
    		CreateMas(&Pmas, size_of_mas);
    	}
    	if (ch1 == '6'){
    		ShowMas(&Pmas, &size_of_mas);
    	}
        printf("До свидания!\n");
    }
    return 0;
}

