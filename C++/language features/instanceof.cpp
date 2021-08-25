#include <iostream>
#include <type_traits>

template<typename Base, typename T>
class Assert{
	public:
		Assert(){}
		bool is_instance(){
			return std::is_base_of<Base, T>::value;
		}
		
		bool is_same(){
			return std::is_same<Base,T>::value;
		}
};

class A{};
class B:public A{};
int main(){
	Assert<A, B> a;
	std::cout<<a.is_instance();
	std::cout<<a.is_same();
}
