#include<bits/stdc++.h>

using namespace std;

class Box{
  int l,b,h;
  
  public:
    Box();
    Box(const int &_l, const int &_b, const int &_h){
        l = _l;
        b = _b;
        h = _h;
    }
    
    Box(const Box &b){}
    
    int getLength(){return this->l;}
    int getBreadth(){return this->b;}
    int getHeight(){return this->h;}
    int CalculateVolume(){return getLength()*getBreadth()*getHeight();}
    
    bool operator<(const Box&b){
        if(this->l < b.l) return true;
        else if(this->b < b.b && this->l == b.l) return true;
        else if(this->h < b.h && this->b == b.b && this->l == b.l) return true;
        return false;
    }
};

std::ostream& operator<<(std::ostream &ss, const Box &b){
    ss<<b.getLength()<<" "<<b.getBreadth()<<" "<<b.getHeight();
    return ss;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
