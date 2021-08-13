# Notes on C

## Memory Management 
Dynamic Memory Allocation in C

1. malloc() 
    - allocates memory and returns `void` pointer. 
    - Initialized values are garbage. 
    - returns null if it failed to reallocate. 
    - `(T*)malloc(<size>*sizeof(T))`

2. alloc() 
    - allocates memory and returns `void` pointer. 
    - Initialize values to 0.
    - `(T*)alloc(<size>, sizeof(T))`
    - returns null of it failed to reallocate.

3. free() 
    - deallocates block of memory. 
    - `free(<pointer>)`

4. realloc() 
    - reallocates block of memory with additional garbage values.             
    - returns null if it failed to reallocate.
    - `(T*)realloc(<pointer>, <size>)`

---
## Pointers in C
Pointers are used for the following reasons:
- indirection
- inexpensive parameter passing
- heap allocation
- function pointers

---
## Constness in C
Specifies that a value of a variable will not be changed. 


| Name                         | Form                             | Modifiable value | Modifiable address |
|------------------------------|----------------------------------|------------------|--------------------|
| pointer to variable          | `T* ptr`                         | yes              | yes                |
| pointer to constant          | `const T* ptr` or `T const* ptr` | no               | yes                |
| constant pointer to variable | `T* const ptr`                   | yes              | no                 |
| constant pointer to constant | `const T* const ptr`             | no               | no                 |

Note that constant variable `const T var` means that `var`'s value(s) should not be changed.

---

## Struct in C
Form:
```C
typedef struct <name>{ 
    <data_type> <data_members>; 
    ... 
} <optional_name>;
```
Note that functions are not allowed to be expressed directly. Function pointers are used to declare member functions in C Struct.


### Function pointers
Function pointers are numerical address for the code of a function. It is declared as follows:
```C
T (*function_pointer)([params]);
```
Any function that matches the function signature of a function pointer are allowed to be referenced. 
```C
T function([params]){...}
.
.
.
function_ptr = &function;
```



---
## Accessors and Modifiers

- `static` - storage specifier. Inside a function it retains the state of a variable even if it goes out of scope. Outside the function, it restrains the visibility of a function or a variable declared as `static`.
- `extern` - tells the compiler, that the bariable we are declaring has been defined elsewhere. 
- `volatile` - tells the compiler that a variabe can be changed outside of our code.
- `const` - means should not be changed