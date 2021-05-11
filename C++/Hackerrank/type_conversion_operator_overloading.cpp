// implicit type conversion defined in class

#include <iostream>
#include <string>

class Base{
		std::string _str;
	public:
		Base(const std::string &str): _str(str){std::cout<<str<<std::endl;}
		Base(){}
};

class A: public Base{
	std::string str_a;
	float _a; 
	public:
		A(float a){
			_a = a;
			str_a = std::to_string(a);
			A::Base();
		}
		
		operator int() const{return int(_a)+1;}
		operator A::Base() const{return Base(str_a);}
};

int main(){
	A a(3.4f);
	std::cout<<int(a);
	(Base) a; // check type conversion
}
