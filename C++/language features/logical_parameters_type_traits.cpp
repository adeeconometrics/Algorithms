// type traits logical parameters
# include <iostream>
# include <type_traits>

// logical disjunction C++17 feature
// logical conjunction C++17 feature
// logical negation C++17 feature
int main(){
	// std::disjunction<param_1,...,param_n>::value
	// std::conjunction<param_1,...,param_n>::value
	// std::negation<B> == std::bool_constant<!bool(B::value)>
	
	// note that bool_constant == template<bool B> integral_constant<bool, B>
}
