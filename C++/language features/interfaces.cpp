// interfaces
# include <iostream>
# include <string>
 
// pure abstract function
class interface{
	public:
		interface(){}
		virtual ~interface(){std::cout<<"destructor";}
		virtual void setName(std::string &str_name) = 0;
		virtual std::string getName() = 0;

};

class A: public interface{
	private:
		std::string name = "A";
	public:
		void setName(std::string &str_name) override{
			name = str_name;
		}
		std::string getName() override{
			return name;
		}
		
};

class B: public interface{
	private:
		std::string name = "B";
	public:
	    B(){std::cout<<"b constructor";}
	    ~B(){std::cout<<"b destructor";}
		void setName(std::string &str_name) override{
			name = str_name;
		}
		std::string getName() override{
			return name;
		}
};

void print(interface *obj){
	std::cout<<obj->getName()<<std::endl;
}

int main(){
// 	A *a = new A();
// 	B *b = ;
// 	print(a);
	print(new B());
	
}
