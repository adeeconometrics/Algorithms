// read and write from file
# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int main(){
	// write file
	ofstream myfile("example.txt");
	if(myfile.is_open()){
		myfile<<"hello world"<<endl;
		myfile<<"hello, world, indeed"<<endl;
		//close
		myfile.close();
	}
	else cout<<"unable to open file";

	// read
	std::string line;
	ifstream myfile("example.txt");
	if(myfile.is_open()){
		while(std::getline(myfile, line)){
			std::cout<<line;
		}
		myfile.close();
	}
	else cout<<"unable to open file";
	return 0;
}
