# include <iostream>

int main(){
	int *p1, *p2;
	p1 = new int;
	*p1 = 53;
	
	p2 = p1;
	
	std::cout<<"*p1 "<<*p1<<"\n";
	std::cout<<"*p2 "<<*p2<<"\n";
}
