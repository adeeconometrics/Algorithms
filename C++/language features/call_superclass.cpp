// calling superclass from derived class
# include <iostream>


class Base{
	public:
		virtual void print(){
			std::cout<<"default, printed from base."<<std::endl;
		}
		
		void specialMethod(){
			std::cout<<"special method from super class"<<std::endl;
		}
};

class Derived: public Base{
	public:
		void print() override{
			std::cout<<"overridden method, printed from Derived"<<std::endl;
		}
		void callSuperclass(){
			Base::specialMethod();
		}
		void print(int a){
			Base::specialMethod();
		}
};

int main(){
	Derived d;
	d.callSuperclass();
	d.print(1);

}
