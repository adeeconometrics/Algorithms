// pointer functions
# include <iostream>

using namespace std;

void function(){
	std::cout<<"hello world."<<endl;
}

// function that takes function as argument
void function2(void (*foo)()){
	foo = &function; // set address of the funciton
	foo(); // call the function
}

int main(){
	void(*foo)(); // construct a function pointer
	foo = &function; // set address of the function 
	foo(); // call the function or use a more general template <funcptr>(<*args>)
	
	function2(function); //specify the address of your function
}
