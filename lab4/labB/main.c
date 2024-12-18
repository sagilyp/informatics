#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELIM " "


int mylen( char *st){
    if (st == NULL){
        return 0;
    }
    char c = st[0];
    int i = 0;
    while(c != 0){
        i++;
        c = st[i];
    }
    return i;
}


void mcp(char *len, char *buf, int n){
    if (buf == NULL){
        exit(2);
    }
    for(int i = 0; i < n; i++){
        len[i] = buf[i];
    }
}


char *in_str()
{
    char buf[81] ={0};
    char *res = NULL;
    int len = 0;
    int n;
    do{
        n = scanf("%80[^\n]", buf);
        if (n < 0){
            return NULL;
        }
        else if (n > 0){
            int chunk_len = mylen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            mcp(res + len, buf, chunk_len);
            len = str_len;
        }
        else{
            scanf("%*c");
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



char *my_strtok(char *p,char delim){
    static char *old;
    int j = 0, k;
    char *buf, *tkn;
    if (p != NULL) {
        k = mylen(p);
        buf = calloc(k + 1, sizeof(char));
        mcp(buf, p, k);
        buf[k] = '\0';
        old = buf;
    }
    else{
        buf = old;
    }
    if(*old == '\0'){
        return NULL;
    }
    while(buf[j] == delim && buf[j] != '\0' ){
        j++;
    }
    tkn = buf+j;
    while (buf[j] != delim && buf[j] != '\0'){
        j++;
    }
    if(buf[j] != '\0') {
        buf[j] = '\0';
        j++;
        old = buf+j;
    }
    else{
        old = buf + j;
    }
    return tkn;
}


char* del_spc(char *str){
    int s_len = mylen(str);
    char *s;
    s = calloc(s_len + 1, sizeof(char));
    mcp(s, str, s_len);
    s[s_len] = '\0';
    char *res = calloc(s_len + 1, sizeof(char));
    int len = 0;
    char *word = my_strtok(str, ' ');
    while (word != NULL){
        int w_len = mylen(word);
        if (w_len > 0){
            mcp(res + len, word, w_len );
            len += w_len;
            res[len] = ' ';
            ++len;
        }
        word = my_strtok(NULL, ' ');
    }
    free(s);
    if (len > 0){
        --len;
    }
    res = realloc(res, (len + 1) * sizeof(char));
    res[len] = '\0';
    return res;
}






char *ind(char *str1){
    char *s1, *res1, *word1;
    int s_len1, c;
    s_len1 = mylen(s1);
    s1 = calloc(s_len1 + 1, sizeof(char));
    mcp(s1, str1, s_len1);
    s1[s_len1] = '\0';
    c = s_len1;
    res1 = calloc(s_len1 + 1, sizeof(char));
    word1 = my_strtok(str1, ' ');
    while (word1 != NULL){
        int w_len;
        w_len = mylen(word1);
        if (w_len > 0){
            s_len1 -= w_len;
            char *poo = res1 + s_len1;
            mcp(poo, word1, w_len);
            if (s_len1 != 0){
                --s_len1;
                res1[s_len1] = ' ';
            }
        }
        word1 = my_strtok(NULL, ' ');
    }
    free(s1);
    if (s_len1 > 0){
        --s_len1;
    }
    res1[c] = '\0';
    return res1;

}



int main(){
    clock_t t1, t2;
    char *B;
    char *A;
    printf("INPUT:\n");
    A = in_str();
    do {
        t1 = clock();
        printf("SOURCE LINE:\"%s\"\n", A);
        B = del_spc(A);
        printf("OUTPUT LINE: \"%s\"\n", B);
        B = ind(A);
        printf("OUTPUT LINE: \"%s\"\n", B);
        free(A);
        free(B);
        printf("INPUT:\n");
        A = in_str();
        t2 = clock();
    }
    while(NULL != A);
    printf("%.10f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
    return 0;
}
