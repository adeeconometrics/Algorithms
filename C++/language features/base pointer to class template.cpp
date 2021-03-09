// base pointers to class template

// using base class as reference to access child function

# include <string>
# include <iostream>

class Base{

//	public:
//		Base(){
//			std::cout<<"base constructor"<<std::endl;
//		}
//		
//		virtual ~Base(){
//			std::cout<<"base destructor"<<std::endl;
//		}
//		
//		virtual std::string getName() = 0;
//		virtual void setName(std::string _name) = 0;
};

template<typename T>
class Child: public Base{
	private:
		std::string name = "child class";
	public:
		Child(){
			std::cout<<"child class constructor"<<std::endl;
		}
		~Child(){
			std::cout<<"child destructor"<<std::endl;
		}
		
		std::string getName(){
			return name;
		}
		
		void setName(std::string _name){
			name = _name;
		}
};

int main(){
	Child<int> c;
	Base *b = c;
	std::cout<< b;
}
