# include <iostream>
# include <string>

std::string translate(const std::string &str){
	std::string comp = "gamma";
	if(str == comp) return "\u03B3";
	return str;
}
int main(){
	std::string str;
	std::getline(std::cin, str);
	std::cout<< translate(str);
//	std::cout<< "\xE1";
}
