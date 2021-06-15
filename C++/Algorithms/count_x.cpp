//count_xX
#include <iostream>
#include <cstring>

int count_x(const char* cstring, int index = 0, int count = 0){
	if(index == strlen(cstring)) return count;
	if(cstring[index] == 'X' || cstring[index] == 'x') count += 1;
	return count_x(cstring, index += 1, count);
}


int main(){
	const char* string = "xhIIxaIIXdIIXJiixiix";
	std::cout << count_x(string);
}
