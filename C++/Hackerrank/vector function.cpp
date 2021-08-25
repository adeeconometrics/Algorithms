// function that return stl structure

# include <iostream>
# include <vector>
# include <sstream>

std::vector<int> function(int arr[], const int &_size){
	std::vector<int> vec;
	for(int i = 0; i<_size; i++)
		vec.push_back(arr[i]);
	
	return vec;
}

std::ostream& operator<<(std::ostream &stream, std::vector<int> v){
	stream<<v.front();
	return stream;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	std::vector<int> v;
	
	v = function(arr, 10);
	
	for(std::vector<int>::iterator it = v.begin(); it!= v.end(); ++it){
		std::cout<<*it<<" ";
	}
}
