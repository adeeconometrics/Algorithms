# include <iostream>

struct Vec{
	int x, y;
	Vec(int a, int b): x(a), y(b){}
	
	Vec add(const Vec &A) const{
		return Vec(x+A.x, y+A.y);
	}
	
	Vec operator+(const Vec &A) const{
		return add(A);
	}
};

std::ostream& operator<<(std::ostream &stream, const struct Vec &other){
	stream<<other.x<<", "<<other.y;
	return stream;
}

int main(){
	Vec a(1,2), b(3,4);
	std::cout<< a+b;
}
