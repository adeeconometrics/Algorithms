// 32-bit RSA encryption 
# include <iostream>
# include <string>
# include <sstream>
# include <random>
# include <cmath>
# include <vector>

template<typename T>
struct pair{
	T first, T second;
	pair(const T&a, const T&b):first(a), second(b){}
	pair();
};


// hex converter
class RSA{
	private:
		std::string msg;
		pair<unsigned int> private_key;
//		const pair<unsigned int> public_key;
		unsigned int p;
		unsigned int q; 
		unsigned int n;
		unsigned int e;
		unsigned int d;
		unsigned int totient;
		
		const int prime_modulus = 3;  
		
	public:
		RSA(){
			set_p();
			set_q();
			set_n();
			set_totient();
//			set_e();
			set_d();
//			set_private_key();
			set_public_key();
		}
		
		std::string encrypt(const std::string &_msg, const unsigned int &_private_key){
			// convert message ascii representation to ss
			std::string m = _msg;
			std::vector<int> v = to_vec(m);
			//encrypt
			int idx = 0;
			for(std::vector<int>::iterator it = v.begin(); it!=v.end(); ++it){
				v[idx] = 
			}
		}
		
		std::string decrypt();
				
		pair<std::string> get_private_key(){
			std::stringstream ss;
			ss<<private_key;
			return ss.str();
		}
		
		void update_e(){
			
		}
	// helper functions 
	private:
		std::default_random_engine generator;
		std::uniform_int_distribution<unsigned int> distribution(10000,40000);
		
		std::string ascii_to_string(std::vector<int> v){
			std::stringstream ss;
			for(std::vector<int>::iterator it = v.begin(); it!=v.end(); ++it){
				ss<<(char)*it;
			}
			
			return ss.str();
		}
		
		std::vector<int> to_vec(const std::string &str){
			std::vector<int> v; 
			std::string _str(str);
			for(std::string::iterator it = _str.begin(); it != _str.end(); ++it){
				v.push_back(int(*it));
			}
			return v;
		}
		
		void set_n(){n = p*q;}
		
		void set_p(){p = generate_prime();}
		
		void set_q(){
			int _q = generate_prime()
			while(p == _q){
				_q = generate_prime();
			}
			q = _q;
		}
		void set_totient(){totient = (p-1)*(q-1);}

		static RSA *m_ptr;
		static unsigned int get_e(){
			std::default_random_engine _generator;
			std::uniform_int_distribution<unsigned int> _distribution(1,m_ptr->totient);
			while(true){
				unsigned int random = _distribution(_generator);
				if(m_ptr->is_coprime(random, m_ptr->totient-1)){
					m_ptr->e = random;
					return;
				}
			}
		}
		
		void set_d(){d = std::pow(e,-1)%totient;}
		
		void set_private_key(){private_key(n,d);}
		pair<unsigned int> get_public_key(){
			pair<unsigned int> p(n,e);
			return p;
		}
		
		//primality test using 6k optimization
		bool is_prime(const unsigned int &_val){
			if(_val <= 3) return _val>1;
			if(_val % 2 == 0 || _val%3 == 0) return false;
			
			int i = 5;
			while(i*i <= _val){
				if(_val%2 == 0 || _val%3 == 0) return false;
				i += 6;
			}
			return true;
		}
		
		bool is_coprime(const unsigned int &a, const unsigned int &b){
			if(gcd(a,b) == 1) return true;
			return false;
		}
		
		unsigned int gcd(const unsigned int &a, const unsigned int &b){
			if(b == 0) return a;
			gcd(b, a%b);
		}
		
		unsigned int generate_prime(){
			while(true){
				unsigned int random = distribution(generator);
				if(is_prime(random)) return random;
			}
		}
				
};

int main(){
	std::string a = "ax"; // const char pointer cannot be indexed 
	for(int i = 0; i<a.length(); i++){
		std::cout<<(int)a[i] << " ";
	}
}
