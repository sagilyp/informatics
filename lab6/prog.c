#include <stdio.h>
#include <stdlib.h>



typedef struct Item {
    char data;
    struct Item *next;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

typedef struct Word {
    Item *head;
    Item *tail;
} Word;

List *list_new() {
    return (List *) calloc(1, sizeof(List));
}



void list_delete(List *list) {
    Item *ptr = list->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(list);
}

void list_print(const List *list) {
    Item *ptr = list->head;
    while (ptr) {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
}

int list_push_back(List *list, int data) {
    Item *ptr = (Item *) malloc(sizeof(Item));
    if (!ptr) {
        return 1;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    return 0;
}


void del_spc(List *list){
    Item *ptr_prev = list->head;
    Item *ptr_prev_prev = NULL;
    Item *ptr = list->head->next;
    int flag = 0;
    while(ptr != NULL){
        if(ptr->data == '\t'){
            ptr->data = ' ';
        }
        else if(ptr_prev->data == '\t'){
        	ptr_prev->data = ' ';
        }
        if(ptr->data == ' ' && ptr_prev->data == ' '){
            ptr_prev->next = ptr->next;
            free(ptr);
            ptr = ptr_prev->next;
            flag = 1;
        }
        else{
        	flag = 0;
        }
        if(ptr != NULL && flag == 0){
        	ptr_prev_prev = ptr_prev;
        	ptr_prev = ptr;
        	ptr = ptr->next;
        }
    }
    if(ptr_prev->data == ' '){
    	ptr_prev_prev->next = NULL;
    	free(ptr_prev);
        list->tail = ptr_prev_prev;
    }
    ptr = list->head;
    if(ptr->data == ' '){
         list->head = ptr->next;
         free(ptr);
     }
}

Item *my_tok_tail(List *list){
    static Item *old;
    Item *ptr = NULL;
    Item *ptr_prev = NULL;
    if(list != NULL) {
        ptr = list->head;
    }
    else{
        ptr = old;
    }
    while(ptr != NULL && ptr->data != ' ' ){
        ptr_prev = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        old = ptr;
    }
    else{
        old = ptr->next;
    }
    return ptr_prev;
}


Item *my_tok_head(List *list){
    static Item *old;
    Item *ptr = NULL, *tmp = NULL;
    if(list != NULL) {
        ptr = list->head;
    }
    else{
        ptr = old;
    }
    while(ptr != NULL && ptr->data == ' ' ){
        ptr = ptr->next;
    }
    tmp = ptr;
    while(tmp != NULL && tmp->data != ' ') {
        tmp = tmp->next;
    }
    old = tmp;
    return ptr;
}

int comp(const Word *p1, const Word *p2){
    Item *alfa = p1->head;
    Item *beta = p2->head;
    int len1 = 1;
    int len2 = 1;
    while(alfa != p1->tail){
        len1++;
        alfa = alfa->next;
    }
    while(beta != p2->tail){
        len2++;
        beta = beta->next;
    }
    alfa = p1->head;
    beta = p2->head;
    int zoo = 0;
    zoo = alfa->data - beta->data;
    if(zoo == 0) {
         while (alfa->next != NULL && beta->next != NULL && zoo == 0 && alfa != p1->tail && beta != p2->tail){
            alfa = alfa->next;
            beta = beta->next;
            zoo = alfa->data - beta->data;
        }
    }
    if(zoo > 0){
        return 1;
    }
    else if(zoo < 0){
        return -1;
    }
    else if(zoo == 0){
        if(len1 > len2) {
            return 1;
        }
        if(len1 < len2) {
            return -1;
        }
        else{
            return 0;
        }
    }
}

void ind_task(List *list){
    Item *Ptr1 = NULL;
    Item *Ptr2 = NULL;
    int i = 1;
    Word *arr = NULL;
    Word buf;
    Ptr1 = my_tok_head(list);
    Ptr2 = my_tok_tail(list);
    while(Ptr1 != NULL && Ptr2 != NULL){
        buf.head = Ptr1;
        buf.tail = Ptr2;
        arr = (Word *)realloc(arr, i*sizeof(Word));
        arr[i-1] = buf;
        i++;
        Ptr2 = my_tok_tail(NULL);
        Ptr1 = my_tok_head(NULL);
    }
    i--;
    qsort(arr, i, sizeof(Word), (int (*)(const void *, const void * ))comp);
    for(int k = 0; k < i-1; k++){
        Item *spc = calloc(1, sizeof (Item));
        spc->data = ' ';
        arr[k].tail->next = spc;
        spc->next = arr[k+1].head;
    }
    arr[i-1].tail->next = NULL;
    list->head = arr[0].head;
    list->tail = arr[i-1].head;
}

int main() {
    	List *l = list_new();
    	int n;
    	n = getchar();
    	while(n != '\n'){
        	list_push_back(l,n);
        	n = getchar();
    	}
    	del_spc(l);
    	printf("Строка до обработки:\n");
    	printf("\"");
    	list_print(l);
    	printf("\"");
    	printf("\n");
    	ind_task(l);
    	printf("Строка после обработки:\n");
    	printf("\"");
		list_print(l);
		printf("\"");
		printf("\n");
    	list_delete(l);	
    return 0;
}
