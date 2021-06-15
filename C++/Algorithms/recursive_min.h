//find_min
#pragma once
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
