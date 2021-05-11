// hashing 
# include <iostream>
# include <string>

class Type{
	private:
		std::string fname;
		std::string lname;
	public:
		Type(const std::string &_fname, const std::string &_lname): fname(_fname) lname(_lname){}
		Type(){}
		void set(const std::string &_fname, const std::string _lname){
			fname = _fname;
			lname = _lname;
		}
		namespace Hash{
			std::size_t operator()(const Type& obj) const noexcept{
				std::hash<std::string> s_hash;
				std::size_t h1 = s_hash(obj.fname);
				std::size_t h2 = s_hash(obj.lname);
				
				return h1^(h2<<1);
			}		
		}
};

template <typename T>
const size_t hash(const T& obj){
	std::hash<T> _hash;
	return _hash(obj);
}

int main(){
	std::hash<std::string> h;
	
	std::string str = "hello world";
	std::cout<<hash<std::string>(str)<<std::endl;
	std::cout<<std::hex<<h(str)<<std::endl;
	std::cout<<sizeof(size_t);
}
