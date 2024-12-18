#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char *name;
    char num[8];
    float mark;
}Mhi;

void mcp(char *len, char *buf, int n){
    if (buf == NULL){
        exit(2);
    }
    for(int i = 0; i < n; i++){
        len[i] = buf[i];
    }
}


int mhi_cmp_name2(const Mhi *a, const Mhi *b){
    return strcmp(b->name, a->name);
}
void insert_sort(Mhi *ptr, int len, int(*compar)(const Mhi *, const Mhi *)){
        for(int i = 1; i < len; i++){
            int k = i;
            while(k > 0 && compar(ptr + k - 1, ptr + k) > 0){
                Mhi tmp = ptr[k-1];
                ptr[k-1] = ptr[k];
                ptr[k] = tmp;
                k--;
            }
        }
}
void shaker_sort(Mhi *ptr, int len, int(*compar)(const Mhi *, const Mhi *)){
    int l = 0, r = len-1, i, ls;
    while(l < r){
        for(i = l; i < r; i++){
            int lk = compar(ptr+i, ptr+i+1);
            if(lk > 0){
                Mhi tmp = ptr[i+1];
                ptr[i+1] = ptr[i];
                ptr[i] = tmp;
                ls = i;
            }
        }
        r = ls;
        for(i = r; i > l; i--){
            int lk = compar(ptr+i-1, ptr+i);
            if(lk > 0){
                Mhi tmp = ptr[i-1];
                ptr[i-1] = ptr[i];
                ptr[i] = tmp;
                ls = i;
            }
        }
        l = ls;
    }
}
void free_struct_name(Mhi *p, int len){
    for(int i = 0; i < len; i++){
        free(p[i].name);
    }
}

int main(){
    int chs1, elm, arr;
    printf("\n""press 1 if you want to sort by quick sort\n"
           "press 2 if you want to sort by shaker sort\n"
           "press 3 if you want to sort by insert sort\n");
    scanf("%d", &chs1);
    printf("\n""we sort by names\n");
    printf("select the number of elements in the sorted arrays\n");
    scanf("%d", &elm);
    printf("select the number of sorted arrays\n");
    scanf("%d", &arr);
    srand(time(NULL));
    Mhi *ptr;
    double time_in;
    for(int i = 0; i < arr; i++){
        ptr = malloc(sizeof(Mhi) * elm );
        for(int j = 0; j < elm; j++){
                    ptr[j].name = malloc(42 * sizeof(char));
                    for(int y = 0; y < 41; y++){
                        if(y == 14 || y == 27){
                            ptr[j].name[y] = ' ';
                        }
                        else{
                            ptr[j].name[y] = rand()%50 + 41;
                        }
                    }
                    ptr[j].name[41] = '\0';
                    for(int i = 0; i < 7; i++){
                        ptr[j].num[i] = '0';
                    }
                    ptr[j].num[7] = '\0';
                    ptr[j].mark = 0;
                }
        clock_t begin = clock();
        switch (chs1){
            case 1:
                    qsort(ptr, elm, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_name2);
                    break;
            case 2:
                    shaker_sort(ptr, elm, mhi_cmp_name2);
                    break;
            case 3:
                    insert_sort(ptr, elm, mhi_cmp_name2);
                    break;
        }
        clock_t end = clock();
         time_in += (double)(end - begin)/CLOCKS_PER_SEC;
        free_struct_name(ptr, elm);
        free(ptr);
        }
    time_in = time_in/arr;
    printf("RESULT TIME: %.10f\n", time_in);
    }
