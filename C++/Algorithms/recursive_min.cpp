//find_min
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& ss, std::vector<int> other){
	ss << "[";
	for(auto i: other)
		ss << i << ",";
	return ss << "]";
}

int min(const std::vector<int>& vector_array, int index = 0, int min_val = INT_MAX){
	if(index == vector_array.size()) return min_val;
	
	if(min_val > vector_array[index])
		min_val = vector_array[index];
	++index;
	return min(vector_array, index, min_val);
}

int main(){
	std::vector<int> v {4,7,64,2,10,23,66,1,6,3,100};
	std::cout << min(v);
}
