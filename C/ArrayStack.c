#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

typedef struct {
    int* m_ptr;
    size_t m_size;
    size_t m_index;
} Stack;

void ArrayStack_ctor(Stack *stk, size_t size){
    stk->m_ptr = (int*) malloc(size*sizeof(int));
    stk->m_size = size;
    stk->m_index = 0;
}

void ArrayStack_dtor(Stack *stk){
    stk->m_index = stk->m_size = 0;
    free(stk->m_ptr);
    stk->m_ptr = NULL;
}

void ArrayStack_push(Stack* stk, int value){
    if(stk->m_size == stk->m_index){
        perror("value exceeds to allocated size.");
        exit(1);
    }
    stk->m_ptr[stk->m_index] = value;
    stk->m_index += 1;
}

void ArrayStack_pop(Stack* stk){
    stk->m_ptr[stk->m_index] = 0;
    stk->m_index -= 1;
}

bool ArrayStack_is_empty(Stack* stk){
    return stk->m_size == 0 && stk->m_ptr == NULL;
}

int ArrayStack_top(Stack* stk){
    return stk->m_ptr[stk->m_index];
}

int ArrayStack_bottom(Stack* stk){
    return stk->m_ptr[0];
}

int main(){

}