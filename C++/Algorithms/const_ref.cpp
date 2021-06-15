//const reference
#include <iostream>
using namespace std;

struct Integer{
	int m_data;
	
	Integer(int a): m_data(a){}
	Integer(){}
};

const Integer* f(int a){
	Integer *ptr = new Integer(a);
	return ptr;
}

int g(const Integer* i){
	return i->m_data;
}

int main(){
	const Integer *i_ptr = f(3);
	cout << f(3)->m_data << '\n';
	cout << g(f(3)) << '\n';
	cout << i_ptr->m_data;
}
