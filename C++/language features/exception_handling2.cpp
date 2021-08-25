# include <iostream>

enum Days{
	MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY
};

int main(){
	int num, num2; //  should be between 1900-2021
	std::cout<<"enter year: ";
	std::cin>>num;
	
	std::cout<<"enter day: ";
	std::cin>>num2;
	try{
		// is this possible with enums?
		if(num<1900 || num>2021)
			throw num;
			
		if(num2 != Days) // this is wrong
			throw num2;
	}catch(int &num){
		std::cout<<"invalid year, it should be between 1900 - 2021";
	}catch(int &num2){
		std::cout<<"invalid day";
	}
}
