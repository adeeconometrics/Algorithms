#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

typedef struct{
    int* m_ptr;
    size_t m_index;
    size_t m_size;
}Array;

void Array_ctor(Array* array, size_t size){
    array->m_ptr = (int*) malloc(size * sizeof(int));
    array->m_index = 0;
    array->m_size = size;
}

void Array_dtor(Array* array){
    free(array->m_ptr);
    array->m_ptr = NULL;
    array->m_size = array->m_index = 0;
}

void Array_insert(Array* array, int element){
    if(array->m_index == array->m_size){
        array->m_size *= 2;
        array->m_ptr = (int*) realloc(array->m_ptr, array->m_size*sizeof(int));
    }
    array->m_ptr[array->m_index] = element;
    array->m_index += 1;
}

bool Array_is_empty(Array *array){
    return array->m_index == 0 && array->m_ptr == NULL;
}

bool Array_is_full(Array* array){
    return array->m_index == array->m_size;
}

int main(void){
    Array a;

    Array_ctor(&a, 5); // initialize 5 elements
    for(int i = 0; i < 100; ++i){
        Array_insert(&a, i);
    }
    printf("%d\n", a.m_ptr[100]);
    Array_dtor(&a);
}