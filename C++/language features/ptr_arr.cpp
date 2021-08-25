# include <iostream>
# include <cstdlib>
using namespace std;

int main(){
	int set[8]={5,10,15,20,25,30,25,40};
	int *nums;
	nums = set; // arrays are referenced without address-of operator
	for(int i=7; i>=0; --i)
		cout<<nums[i]<<endl; // pointers referred in array can be accessed in this manner
	
	cout<<"\ndereferencing mode of access"<<endl;
	for(int i=7; i>=0; --i) // dereferencing operator also works 
		cout<<*(nums+i)<<endl;
	
} 
