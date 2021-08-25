//abstract class
# include <iostream>

// it is possible to access derived class function from base given that it is overriden from 
// a virtual function defined in the abstract class
class Abstract{
	const char* _name = "Abstract class";
	public:
		Abstract(){
			std::cout<<"Abstract class constructor is called"<<std::endl;
		}
		
		virtual void setName(const char* name){
			_name = name;
		}
		virtual const char* getName(){
			return _name;
		}
};

class Derived: public Abstract{
	private:
		const char* _name = "derived class";
		
	public:
		Derived(){
			std::cout<<"derved class constructor is called"<<std::endl;
		}
		void setName(const char* name) override{
			_name = name;
		}
		const char* getName() override{
			return _name;
		}
};

int main(){
	Abstract *a = new Derived;
	std::cout<<a->getName();
}
