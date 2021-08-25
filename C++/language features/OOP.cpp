// OOP
# include <iostream>
# include <string>
// abstract class
class Abstract{
	public:
		virtual ~Abstract(){
			std::cout<<"destructor for abstract class"<<std::endl;
		}
		virtual void getName() = 0; // pure virtual function
};
// base class
class Base: virtual public Abstract{
	// note that abstract class should be declared virtual if inheritance
	// is hierarchical, it will make disambiguation a lot simpler since
	// calling superclass constructor from the subclass will become optional 
	public:
		Base(){
			std::cout<<"constructor for Base class"<<std::endl;
		}
		~Base(){
			std::cout<<"destructor for Base class"<<std::endl;
		}
		
		void getName() override{
			std::cout<< name <<std::endl;
		}
		
	private:
		std::string name = "Base class";
};
// child class
class ChildRight: public Base{
	public:
		ChildRight():Base(){
			std::cout<<"constructor for ChildRight class"<<std::endl;
		}
		~ChildRight(){
			std::cout<<"destructor for ChildRight class"<<std::endl;
		}
		
		void getName() override{
			std::cout<< name <<std::endl;
		}
		
		void setName(std::string newName){
			name = newName;
		}
	private:
		std::string name = "ChildRight";
};
// child class 2
class ChildLeft: public Base{
	public:
		ChildLeft():Base(){
			std::cout<<"constructor for ChildLeft class"<<std::endl;
		}
		~ChildLeft(){
			std::cout<<"destructor for ChildLeft class"<<std::endl;
		}
		
		void getName() override{
			std::cout<< name <<std::endl;
		}
		
		void setName(std::string newName){
			name = newName;
		}
	private:
		std::string name = "ChildLeft";
};
// multiple inheritance
class MultipleInheritance: public ChildRight, public ChildLeft{
	public:
		MultipleInheritance():ChildRight(), ChildLeft(){
			std::cout<<"constructor for MultipleInheritance"<<std::endl;
			// call superclass
			ChildRight::setName("superclass ChildRight is called from MultipleInheritance");
			// call superclass method
			ChildRight::getName();
		}
		void getName() override{
			std::cout<< name <<std::endl;
		}
	private:
		std::string name = "MultipleInheritance";
};
// interfacing using abstract classes
void PrintName(Abstract *obj){
	obj->getName();
}

int main(){
	MultipleInheritance *m = new MultipleInheritance();
	PrintName(m);
	delete m;
}
