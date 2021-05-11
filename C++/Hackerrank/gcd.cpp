#include <iostream>
#include <type_traits>


int gcd(const int &a, const int &b){
	if (b == 0) return a;
	else{
		std::cout<< a << " = "<< b <<"*" <<a/b << " + " << a%b<<std::endl;
		return gcd(b, a%b);
	}
}

int main(){
	int n1, n2;
	
	while(true){
		
		std::cin>>n1>>n2;	
		std::cout<<"gcd = " <<gcd(n1, n2);
		std::cout<<"\n---------------\n";
		std::cin.get();
		if(n1 == 0 && n2 == 0){
			std::cout<<"\nbreaks;\n";
			break;
		}
	}
	return 0;
}
