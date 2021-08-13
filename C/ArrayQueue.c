#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>

typedef struct {
    int* m_ptr;
    size_t m_size;
    size_t m_back;
    size_t m_front;
} Queue;

void ArrayQueue_ctor(Queue *q, size_t size){
    q->m_ptr = (int*) malloc(size*sizeof(int));
    q->m_size = q->m_back = 0;
}

void ArrayQueue_dtor(Queue* q){
    q->m_back = q->m_size = 0;
    free(q->m_ptr);
    q->m_ptr = NULL;
}

bool ArrayQueue_is_empty(Queue* q){
    return q->m_size == 0 || q->m_ptr == NULL;
}

bool ArrayQueue_is_full(Queue* q){

}

void ArrayQueue_push(Queue* q, int value){
    if(q->m_size == q->m_back){
        perror("Operation cannot proceed. Capacity is already full.");
        exit(1);
    }
    q->m_back = (q->m_back + 1)% q->m_size;
    q->m_ptr[q->m_back] = value;
    q->m_back += 1;
}

void ArrayQueue_pop(Queue* q){
    if(ArrayQueue_is_empty(q)){
        perror("Operation cannot proceed. Queue is already empty.");
        exit(1);
    }
    q->m_ptr[q->m_front] = 0;
    q->m_front = (q->m_front + 1) % q->m_size;
}

int ArrayQueue_top(Queue* q){
    return q->m_ptr[q->m_front];
}

int ArrayQueue_bottom(Queue* q){
    return q->m_ptr[q->m_back];
}

int main(){
    struct Queue *q;
    ArrayQueue_ctor(&q, 5);

    for(int i = 0; i < 5; ++i){
        ArrayQueue_push(&q, i);
        printf("%d\n", ArrayQueue_bottom(&q));
    }
}