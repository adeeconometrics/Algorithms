#include <iostream>

using namespace std;

int main(){
	int *p1, *p2;
	p1 = new int;
	*p1 = 50;
	cout<<"*p1 = "<<*p1<<endl;

// as much as possible use stack-allocated entities
// in cases where it needs to have a lot of memory
// heap-allocated entities are the only way to interface with 
// note that these entities has to be destroyed to avoid memory leaks
	
//	system("pause") - Linux command
//  system("sleep") - Windows
}
