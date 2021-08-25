// parameter passing 

# include <iostream>

void function(const int *ptr){*ptr += 1;}

void function(const int &a){a += 1;}

int main(){
	int *ptr = nullptr;
	int a = 5;
	ptr = &a;
	
	function(ptr);
	function(a);
	
	std::cout<< a << std::endl;
}
