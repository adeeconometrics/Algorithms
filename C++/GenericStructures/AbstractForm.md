### Abstract Form:

- Declaration of intent.
- Directives
```
#pragma once
#include "IteratorConcreteArray.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>
```
- Class
    - Type Definitions
        ```
        typedef int value_type;
        typedef int *pointer_type;
        typedef int &reference_type;
        typedef size_t size_type;

        typedef Array_Iterator iterator;
        typedef cArray_Iterator const_iterator;
        ```
    - Private members
    - Constructors
    - Destructors
    - Operators
    - methods
    - helper methods {void, size_t, int, bool}
    - iterators
    - operator <<
    - private functions