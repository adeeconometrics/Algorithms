//func(ptr ptrvar);
//func(&ptrvar);
# include <iostream>
typedef double* DoublePtr;

using namespace std;

double func(DoublePtr a, DoublePtr b){
	return (*a)*(*b);
}

double func2(double &a, double &b){
	return a*b;
}


int main(){
	double a = 0.5, b=0.6;
	DoublePtr ptra=&a, ptrb=&b;
	cout<<"passing params by address"<<endl;
	cout<<func(&a,&b)<<endl;
	cout<<"passing params by pointers"<<endl;
	cout<<func2(*ptra,*ptrb)<<endl;
}
