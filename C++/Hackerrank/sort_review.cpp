#include <iostream>

void sort(int *ptr, const int &size){
	for(int i = 0; i<size; i++){
		for(int j = i; j<size; j++){
			if(ptr[i] > ptr[j]){
				int temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

int main(){
	int array[] = {3,2,5,1,7,9};
	int *ptr = array;
	int size = sizeof(array)/sizeof(int);
	sort(ptr, size);
	
	// print
	for(int i = 0; i<size; i++)
		std::cout<< array[i] << " ";	
}
