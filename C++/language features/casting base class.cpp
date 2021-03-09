// reinterpret_cast<>
# include <iostream>
# include <string>

class Base{
	public:
		Base(){std::cout<<"base constructor"<<std::endl;}
		~Base(){std::cout<<"base destructor"<<std::endl;}
		
//		virtual std::string getName() = 0;
//		virtual void setName(std::string _name) = 0;
};

class Child{
	private:
		std::string name = "child class";
	public:
		Child(){std::cout<<"child class constructor"<<std::endl;}
		~Child(){std::cout<<"child destructor"<<std::endl;}
		
		std::string getName(){
			return name;
		}
		
		void setName(std::string _name){
			name = _name;
		}
};

int main(){
	Child *a = new Child;
	Base *b = reinterpret_cast<Base*>(&a);
	b->setName();
}
