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

char *in_str(FILE *f)
{
    char buf[81] ={0};
    char *res = NULL;
    int len = 0;
    int n;
    do{
        n = fscanf(f,"%80[^\n]", buf);
        if (n < 0){
            return NULL;
        }
        else if (n > 0){
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            mcp(res + len, buf, chunk_len);
            len = str_len;
        }
        else{
            fscanf(f, "%*c");
        }
    } while(n > 0);
    if(len > 0){
        res[len] = '\0';
    }
    else{
        res = calloc(1, sizeof(char));
    }
    return res;
}

Mhi *init(FILE *f, int *k){
        Mhi *p = NULL;
        char *bum;
        float sc;
        char *str;
        while (!feof(f)){
            int m;
            Mhi item;
            str = in_str(f);
            if (str == NULL){
                break;
            }
            bum = in_str(f);
            if (bum == NULL){
                break;
            }
            m = fscanf(f, "%f", &sc);
            if(m == EOF){
                break;
            }
            item.name = str;
            fscanf(f, "%*[^\n]");
            fscanf(f, "%*1[\n]");
            for (int q = 0; q < 7; q++) {
                item.num[q] = bum[q];
            }
            item.num[7] = '\0';
            item.mark = sc;
            p = realloc(p, (*k) * sizeof(Mhi));
            p[(*k) - 1] = item;
            (*k)++;
            free(bum);
            //free(str);
            sc = 0;
        }
        fclose(f);
        return p;
}
void point_print(const Mhi *d){
    printf("{%s, %s, %.2f}", d->name, d->num, d->mark);
}

void print_arr(const char *msg, const Mhi *arr, int len){
    printf("%s", msg);
    for(int i = 0; i<len; i++){
        printf("a[%d] = ", i);
        point_print(arr + i);
        printf("\n");
    }
}

int mhi_cmp_name1(const Mhi *a, const Mhi *b){
    return strcmp(a->name, b->name);
}

int mhi_cmp_name2(const Mhi *a, const Mhi *b){
    return strcmp(b->name, a->name);
}

int mhi_cmp_num1(const Mhi *a, const Mhi *b){
    return strcmp(a->num, b->num);
}
int mhi_cmp_num2(const Mhi *a, const Mhi *b){
    return strcmp(b->num, a->num);
}

int mhi_cmp_mark2(const Mhi *a, const Mhi *b){
    float c = a->mark - b->mark;
    float eps = 0.0000000001;
    if(c > 0){
        return 1;
    }
    if (c < 0){
        return -1;
    }
    if (c < eps && c > -eps){
        return 0;
    }
}

int mhi_cmp_mark1(const Mhi *a, const Mhi *b){
    float c = b->mark - a->mark;
    float eps = 0.0000000001;
    if(c > 0){
        return 1;
    }
    if (c < 0){
        return -1;
    }
    if (c < eps && c > -eps){
        return 0;
    }
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

int main() {
    int k = 1;
    FILE *f;
    Mhi *ptr;
    f = fopen("input.txt","r");
    if(!f){
        printf("Error, text file is undeclarated");
        return 10;
    }
    ptr = init(f, &k);
    k--;
    int chs = 0, chs2 = 0;
    do {
        printf("\n""press 0 if you don't want to sort\n"
               "press 1 if you want to sort by quick sort\n"
               "press 2 if you want to sort by shaker sort\n"
               "press 3 if you want to sort by insert sort\n"
               "press 4 if you want to see array\n");
        scanf("%d", &chs);
        int s = 0;
        if(chs != 0 && chs != 4) {
            printf("\n""press 1 if you want to sort by names\n"
                   "press 2 if you want to sort by group numbers\n"
                   "press 3 if you want to sort by grades\n");
            scanf("%d", &chs2);
            printf("if you want to sort in ascending order, press 1, otherwise press 2\n");
            scanf("%d", &s);
        }
            if(chs == 1) {
                switch (chs2) {
                    case 1:
                        if (s == 1) {
                            qsort(ptr, k, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_name2);
                        } else {
                            qsort(ptr, k, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_name1);
                        }
                        printf("the array has been sorted!\n");
                        break;
                    case 2:
                        if (s == 1) {
                            qsort(ptr, k, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_num2);
                        } else {
                            qsort(ptr, k, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_num1);
                        }
                        printf("the array has been sorted!\n");
                        break;
                    case 3:
                        if (s == 1) {
                            qsort(ptr, k, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_mark2);
                        } else {
                            qsort(ptr, k, sizeof(Mhi), (int (*)(const void *, const void *)) mhi_cmp_mark1);
                        }
                        printf("the array has been sorted!\n");
                        break;

                }
            }
            if(chs == 2) {
                switch (chs2) {
                    case 1:
                        if (s == 1) {
                            shaker_sort(ptr, k, mhi_cmp_name2);
                        } else {
                            shaker_sort(ptr, k, mhi_cmp_name1);
                        }
                        printf("the array has been sorted!\n");
                        break;
                    case 2:
                        if (s == 1) {
                            shaker_sort(ptr, k, mhi_cmp_num2);
                        } else {
                            shaker_sort(ptr, k, mhi_cmp_num1);
                        }
                        printf("the array has been sorted!\n");
                        break;
                    case 3:
                        if (s == 1) {
                            shaker_sort(ptr, k, mhi_cmp_mark2);
                        } else {
                            shaker_sort(ptr, k, mhi_cmp_mark1);
                        }
                        printf("the array has been sorted!\n");
                        break;

                }
            }
            if(chs == 3) {
                switch (chs2) {
                    case 1:
                        if (s == 1) {
                            insert_sort(ptr, k, mhi_cmp_name2);
                        } else {
                            insert_sort(ptr, k, mhi_cmp_name1);
                        }
                        printf("the array has been sorted!\n");
                        break;
                    case 2:
                        if (s == 1) {
                            insert_sort(ptr, k, mhi_cmp_num2);
                        } else {
                            insert_sort(ptr, k, mhi_cmp_num1);
                        }
                        printf("the array has been sorted!\n");
                        break;
                    case 3:
                        if (s == 1) {
                            insert_sort(ptr, k, mhi_cmp_mark2);
                        } else {
                            insert_sort(ptr, k, mhi_cmp_mark1);
                        }
                        printf("the array has been sorted!\n");
                        break;

                }
            }
            if(chs == 4) {
                print_arr("\n", ptr, k);
            }

    }while(chs != 0);
    print_arr("Before sort:\n", ptr, k);
    f = fopen("output.txt", "w");
    if(!f) {
        printf("Error, text file is undeclarated");
        return 10;
    }
    for(int i = 0; i < k; i++){
        fprintf(f, "{ %s, %s, %.2f }\n", (ptr+i)->name, (ptr+i)->num, (ptr+i)->mark );
    }
    fclose(f);
    printf("\nGoodbye!!!\n");
    return 0;
}
