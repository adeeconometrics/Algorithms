// function that returns a pointer
# include <iostream>

using namespace std;

// returns array
int * array(){
	static int arr[10]; // has to be static, otherwise data is ruined beyond this scope
	// add elements
	for(int idx=0; idx<10; idx++){
		arr[idx]=idx+1;
	}
	return arr; // points to the address of the array
}

int main(){
	int *p;
	int size = 10;
	p = array();
	// output result
	for(int idx=0; idx<size; idx++){
		std::cout<<*(p+idx)<<endl;
	}
}
