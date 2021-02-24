// virtual function to child class 

# include <iostream>

class BaseClass{
	public:
		virtual const char* getName(){
			return "BaseClass";
		} 
};

class Child: public BaseClass{
	public:
		const char* getName() override{
			return "Child class";
		}
		
		virtual void methodfromChild(){
			std::cout<<"successfully done"<<std::endl;
		}
};

// base class can serve as a pointer reference for child class
// but methods declared only in child class (even virtual functions)
// remain exclusive for that class
void print(BaseClass *obj){
	std::cout<<obj->getName()<<std::endl;
}

// base class can be a reference to child class so long
// as the methods of base class are referred, otherwise throws compiler error
void print(BaseClass &obj){
//	obj.methodfromChild();
	std::cout<<obj.getName()<<std::endl;
}

int main(){
	
	BaseClass *ptr_b = new Child();
	print(ptr_b);

	Child c;
	print(c);
}
