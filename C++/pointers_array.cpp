#include <iostream>
using namespace std;
typedef int *IntPtr; 

int main(){
	IntPtr p;
	int a[10];

	for (int idx = 0; idx<10; idx++) a[idx] = idx;
	
	for (int idx = 0; idx<10; idx++) cout<<a[idx]<<" ";
	
	p =  a;
	std::cout<<"\n contents pointed to by pointer p by p[idx]\n";
	for(int idx = 0; idx<10; idx++) cout<<p[idx]<<" ";
		
	std::cout<<"\n contents pointed to by pointer p by *(p+idx) \n";
	for(int idx = 0; idx<10; idx++) cout<<*(p+idx)<<" ";
	// writing new values on our pointer
	for(int idx = 0; idx<10; idx++) p[idx] = p[idx]+1;

	std::cout<<"\n new contents pointed to by pointer p \n";
	for(int idx = 0; idx<10; idx++) cout<<p[idx]<<" ";
}
