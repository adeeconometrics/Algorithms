// stack 

# include <iostream>
# include <stack>

int main(){
	std::stack<int> s;
	
	for(int i = 0; i<10; i++) s.push(i);
	for(int i = 0; i<s.size(); i++){
		std::cout<<s.top() << " ";
		s.pop();
	}
	
}
