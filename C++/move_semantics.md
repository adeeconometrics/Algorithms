# Move Semantics 
 - reasons for move semantics 
 - concepts to understand to implement move semantics
 - rvalues and lvalues

Purpose of move semantics: avoid costly and unnecessary deep copying (1).
 1. Move  semantics is particularly powerful where passing by reference and passing by value are both needed.
 2. Move  semantics give you finer control of which part of your object to be moved.

----
### RValue Reference

Used for:
1. Move Semantics
2. Perfect Forwarding

Prerequisite: rvalue and lvalue. 

lvalue and lvalue reference example in C++11:
```C++
int a = 5; // lvalue
int &b = a; //lvalue reference
```

rvalue and rvalue reference example in C++11:
```C++
// 5 is an example of rvalue
int && c; //rvalue reference
```

Sample program:
```C++
#include <iostream>

void f(int&& a){
	a = 1;
	std::cout << "R value reference. Value of a: "<< a << std::endl;
}

void f(int& a){
	a = 0;
	std::cout << "L value reference. Value of a: "<< a << std::endl;
}

int main(){
	int b = 5;
	std::cout << "Before: " << b << std::endl;
	f(std::move(b)); // move constructor affects the value of v
	std::cout << "After: "<<b << std::endl;
	std::cout << "------------------------------\n";
	std::cout << "Before: " << b << std::endl;
	f(b); // calls lvalue reference
	std::cout << "After: "<<b << std::endl;
}
```

Result:
```
Before: 5
R value reference. Value of a: 1
After: 1
------------------------------
Before: 1
L value reference. Value of a: 0
After: 0
```

Note that you can only overload a function, if ever you make use of rvalue and lvalue reference without `pass-by-value` that has the same function signiture. This will result to compiler error becuase of ambiguity. 

- The return value of functions are rvalues.

---

The compiler chooses a move constructor in certain situations where the object is being initialized by another object of the same type that is about to be destroyed and no longer needs its resources.

---
### References
1. Bo Quian (2014). [C++11: Rvalue Reference - Move Semantics](https://www.youtube.com/watch?v=IOkgBrXCtfo). 