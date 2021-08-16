#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct{
    struct node* front;
    struct node* back;
    size_t size;
} List;

void ctor(List* list){
    list->front = list->back = NULL;
    list->size = 0;
}

void dtor(List* list){
    clear(list);
}

void push(List * list, int value){
    node* _node = (struct node*)malloc(sizeof(node));
    _node->value = value;

    if(is_empty(list)){
        list->back = list->front = _node;
    } else{
        _node->next = list->front;
        list->front = _node;
    }
    list->size += 1;
}

void pop(List *list){
    if(!is_empty(list)){
        node* _node = list->front;
        list->front = list->front->next;

        free(_node);
        _node = NULL;

        list->size -= 1;
    }
}

bool is_empty(List* list){
    return list->front == NULL && list->back == NULL;
}

bool is_element(List *list, int value){
    for(node* p = list->front; p!= NULL; p = p->next){
        if(p->value == value) return true;
    }
    return false;
}

void clear(List* list){
    if(!is_empty(list)){
        node* p1 = list->front;
        node* p2 = NULL;
        while(p1 != NULL){
            p2 = p1->next;
            free((int*)p1);
            p1 = p2;
        } 

        list->size = 0;
        list->front = list->back = NULL;
    }
}

void display(List* list){
    for(node* p = list->front; p!= NULL; p = p->next){
        printf("%d ->", p->value);
    }
}

int top(List *list){
    return list->front->value;
}

int bottom(List *list){
    return list->back->value;
}

int main(void){
    
}