// abstract classes
# include <iostream>
# include <string>

// pure abstract class 
class Interface{
	public:
		Interface(std::string name){std::cout<<"constructor from Interface class\n";} // note that there is no such thing as virtual constructors
		virtual ~Interface(){std::cout<<"destructor from Interface class\n";} // virtual destructors
		virtual void printName() = 0;
};

class A: public Interface{
	private:
		std::string name = "entity from class A";
		
	public:
		A(){std::cout<<"constructor of A\n";}
		~A(){std::cout<<"destructor of A\n";}
		
		void printName() override{
			std::cout<<name<<std::endl;
		}
};

class B: public Interface{
	private:
		std::string name = "entity from class B";
		
	public:
		B(){std::cout<<"constructor of B\n";}
		~B(){std::cout<<"destructor of B\n";}
		
		void printName() override{
			std::cout<<name<<std::endl;
		}
};

// you can only make references to interfaces as pointers 
void Print(Interface *obj){
	obj->printName();
}

int main(){
	A *a = new A();
	B *b = new B();
	Print(a);
	Print(b);
	delete a;
	delete b;

}
