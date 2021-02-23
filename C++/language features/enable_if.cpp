// type traits
# include <iostream>
# include <type_traits>

class A{
	public:
		int a, b;
		float c,d;
};

class B: public A{
	public:
		char e;
};
// compiler prefers templated functions first
template<typename T> typename std::enable_if<std::is_same<T,A>::value>::type 
func(T a){
	std::cout<<"yes\n";
}
/*
template<typename T> typename std::enable_if<std::is_base_of<A,T>::value>::type // checks if T is subclass of A or A itself
func(T a){
	std::cout<<"yes\n"; // returns yes to class B
}
*/
void func(...){
	std::cout<<"no\n";
}
int main(){
	A a;
	B b;
	func(a);// yes
	func(b);// no - therefore B is not of type A
	
}
