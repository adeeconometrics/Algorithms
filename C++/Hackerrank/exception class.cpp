//base exception
# include <iostream>

class Exception: public std::exception{
	private:
		const char *msg;
	public:
		Exception(const char * _msg): msg(_msg){}
		const char* what(){
			return msg;
		}
};

int main(){
	int a, b, c;
	std::cin>>a>>b>>c;
	try{
		if(a>b) throw Exception("invalid");
		if(b>c) throw Exception("invalid");
	}catch(Exception &e){
		std::cerr<<e.what()<<std::endl;
	}
	
	std::cout<<"end";
}
