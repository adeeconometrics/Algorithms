# include <iostream>
# include <string>
//down casting 

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
	d = dynamic_cast<Derived*>(b); // fails because b is incomplete type of d, returns d(0)
	
	if(d == b) std::cout<<"type conversion succeeds"<<std::endl;
	else if(d == 0) std::cout<<"type conversion failed."<<std::endl;
	
	std::cout<<d->printStr();
	std::cout<<d->num();
	
	std::cout<<std::endl;
	
	Base *b1 = new Derived();
	Derived *d1;
	d1 = dynamic_cast<Derived*>(b1);
	
	if(d1 == b1) std::cout<<"type conversion succeeds"<<std::endl;
	else if(d1 == 0) std::cout<<"type conversion failed."<<std::endl;
	
	std::cout<<d1->printStr();
	std::cout<<d1->num();
}
