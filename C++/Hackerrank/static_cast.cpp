# include <iostream>
# include <string>
//upcasting and downcasting

class Base{
	public:
		virtual void getName(){
			std::cout<<"Base class"<<std::endl;
		}		
};

class Derived: public Base{
	std::string str = "this works";
	
	public:
		void getName()override{
			std::cout<<"Derived class"<<std::endl;
		}
		
		void setStr(const std::string &_str){
			str = _str;
		}
		
		std::string printStr(){
			return "hi";
		}
		
		int num(){
			return 5;
		}
};

int main(){
	const char * p = "this works";
	Base *b = new Base;
	Derived *d;
	d = static_cast<Derived*>(b); // downcast

	std::cout<<d->printStr();
	std::cout<<d->num();
	
	std::cout<<std::endl;
	
	Base b1;
	Derived *d1;
	d1 = static_cast<Derived*>(&b1); // reference downcast
	
	std::cout<<d1->printStr();
	std::cout<<d1->num();
}
