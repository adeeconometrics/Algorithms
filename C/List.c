#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int value;
} node;

typedef struct{
    node* head;
    node* back;
    node* next; 
    size_t size;
} List;

void ctor(List* list){
    list->head = list->back = NULL;
    list->size = 0;
}

void dtor(List* list){
    list->size = 0;
    if(!is_empty(List)){
        clear(list);
    }
}

void insert(List * list, int value){

}

bool is_empty(List* list){
    return list->head == NULL && list->back == NULL;
}

bool is_element(List *list){
    for(List* ptr = list; ptr != NULL; ptr = ptr->next){
        free(ptr);
    }
}

void clear(List* list){

}

int main(void){}