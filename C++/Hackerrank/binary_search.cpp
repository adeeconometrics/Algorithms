//binary search

#include <iostream>

void binary_search(const int *ptr_arr, int item, int n){
	int low(1), mid, high(n);
	while(low <= high){
		mid = (low + high)/2;
		if(ptr_arr[mid] == item){
			std::cout<<"item is found at position: " << mid << std::endl;
			break;
		}
		else if(ptr_arr[mid] < item)
			low = mid +1;
		else
			high = mid - 1;
	}
}

int main(){
	int *ptr_arr, n, x, item;
	std::cout << "Enter size of array: ";
	std::cin >> n;
	
	ptr_arr = new int[n];
	
	std::cout << "Enter " << n << "elements in ascending order.";
	for(int i = 0; i < n; ++i)
		std::cin >> ptr_arr[i];
	
	std::cout<<"Enter element to search: ";
	std::cin>>item;
	
	binary_search(ptr_arr, item, n);
	
	return 0;
}
