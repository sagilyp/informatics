#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <time.h>
#include "mystring.h"

int main(){
    clock_t t1, t2;
    char *B;
    char *A;
    printf("INPUT:\n");
    A = readline("");
    do {
        t1 = clock();
        printf("SOURCE LINE:\"%s\"\n", A);
        A = del_spc(A);
        B = ind(A);
        printf("OUTPUT LINE: \"%s\"\n", B);
        free(A);
        free(B);
        //A = NULL;
        //B = NULL;
        printf("INPUT:\n");
        A = readline("");
        t2 = clock();
    }
    while(NULL != A);
    printf("%.10f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    return 0;
}
