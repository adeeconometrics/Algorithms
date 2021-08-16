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

void add_front(List* list, int value){
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

void add_back(List * list, int value){
    node* _node = (struct node*)malloc(sizeof(node));
    _node->value = value;

    if(is_empty(list)){
        list->back = list->front = _node;
    } else{
        list->back->next = _node;
        list->back = _node;
    }
    list->size += 1;
}

void remove_front(List* list){
    if(!is_empty(list)){
        node* _front = list->front;
        list->front = list->front->next;
        free(_front);
        _front = NULL;
    }
}

void remove_back(List* list){
    if(!is_empty(list)){
        node* _prev = list->front;
        while(_prev->next != list->back){
            _prev = _prev->next;
        }
        list->back = _prev;

        free(_prev->next);
        _prev->next = NULL;
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

int main(void){
    List* list;
    for(int i = 0; i <10; ++i){
        add_front(&list, i+1);
    }
    display(&list);
}