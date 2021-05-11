//virtual functions
# include <iostream>
# include <string>


class Base{
	public:
		Base(){
			std::cout<<"base is created"<<std::endl;
		}
		
		virtual void setname() = 0;
};

class Derived: public Base{
	std::string str = "";
	public:
		Derived(){
			std::cout<<"derived class is created."<<std::endl;
		}
		
		void setname() override{}
		void setname(const std::string &_str){
			str = _str;
		}
		
		void getname(){
			std::cout<<str;
		}
};

int main(){
	std::string name = "name";
	Derived d;
	d.setname(name);
	d.getname();
}
