// exception handling
# include <iostream>
# include <exception>

class Exception: public std::exception{
	// without const throw() calls std::exception
	const char* what() const throw(){
		return "My exception happened";
	}
};

int main(){
	
	Exception ex;
	try{
		throw ex;
	}catch(std::exception &ex){
		std::cout<<ex.what()<<"\n";
	}
}
