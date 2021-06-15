// algorithms 
#include <iostream>

//uniqueness
// make generic with constraints on comparable objects
bool is_unique(const int array[], size_t size){
	for(size_t i = 0; i < size; ++i)
		for(size_t j = i; j < size - 1; ++j)
			if(array[i] == array[j]) return true;
	return false;
}

// find_max algorithm
// make generic with constraints to comparable objects
int find_max(const int array[], size_t size){
	int max = INT_MIN;
		
	for(size_t i = 0; i < size; ++i)
		if(array[i] > max)
			max = array[i];
			
	return max;
}
// find_min algorithm
// make generic with constraints to comparable objects
int find_min(const int array[], size_t size){
	int min = INT_MAX; // value 2147483647
		
	for(size_t i = 0; i < size; ++i)
		if(array[i] < min)
			min = array[i];
			
	return min;
}

struct MinMax{
	int min{0}, max{0};
	MinMax(int i_min, int i_max):min(i_min), max(i_max){}
	friend std::ostream& operator << (std::ostream& ss, const MinMax& obj);
};

MinMax find_extrema(const int array[], int size){
	int min = INT_MAX; // value 2147483647
	int max = INT_MIN;
	
	for(size_t i = 0; i < size; ++i){
		if(array[i] > max)
			max = array[i];
		if(array[i] < min)
			min = array[i];
	}
			
	return MinMax(min, max);
}

std::ostream& operator << (std::ostream& ss, const MinMax& obj){
	return ss << "{" << obj.min << "," << obj.max << "}"; 
}

size_t factorial(size_t&& number){
	if(number == 0) return 1;
	return number*factorial(number-1);
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, b%a);
}

int fib(int n){
	if(n<=1) return n;
	return fib(n-1) + fib(n-2); 
}

//int ifib(int n){
//	int f_0{0};
//	int f_1{1};
//	int result{0};
//	for(size_t i = 2; i < n; ++i)
//		result = f_
//}

int main(){
//	int array[] = {1,2,3,4,5,6,7,8,9,-1};
//	std::cout << find_extrema(array, 10)
std::cout << gcd(360, 60);
}
