// proof of concept 
# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

struct Node{
	std::string n_string;
	std::string name;
	std::string title;
	std::string genre;
	Node(std::string _name, std::string _title, std::string _genre):name(_name), title(_title), genre(_genre){}
	
	operator const char*(){
		std::ostringstream n_str;
		n_str<<"name: "<<name<<"\n"<<"title: "<<title<<"\n"<<"genre: "<<genre<<std::endl;
		
		n_string = n_str.str();
		return n_string.c_str();
	}
};

int main(){
	Node node("Steve", "Terminator", "action");
	std::cout<< node;
	std::ofstream f;
	f.open("sample.txt");
	f<<node;
	f.close();
}
