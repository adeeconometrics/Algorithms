// integral constants
# include <iostream>
# include <type_traits>

// true_type = std::integral_constant<bool, true>
// false_type = std::integral_constant<bool, false>

int main(){
	// expr::value - returns value that can be evaluated
	std::cout<< std::integral_constant<bool, true>::value<<std::endl; 
	std::cout<<std::true_type::value<<std::endl;
	
	std::cout<< std::integral_constant<bool, false>::value<<std::endl;
	std::cout<<std::false_type::value<<std::endl;
}
