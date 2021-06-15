//recursion: sum of even numbers
#include <iostream>
#include <vector>

std::vector<int> even_array;

std::ostream& operator<<(std::ostream& ss, std::vector<int> other){
	ss << "[";
	for(auto i: other)
		ss << i << ",";
	return ss << "]";
}

int sum_even(const std::vector<int>& vector_list, int counter = 0, int sum = 0){
	if(counter == vector_list.size()) return sum;
	
	if(vector_list[counter] % 2 == 0){
		even_array.push_back(vector_list[counter]);
		sum += vector_list[counter];
	}
	return sum_even(vector_list, counter+=1, sum);
}

int main(){
	std::vector<int> vector{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	std::cout << sum_even(vector) << '\n';
	std::cout << even_array;
}
