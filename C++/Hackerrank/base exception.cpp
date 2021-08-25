#include <iostream>

using namespace std;
class Exception: public std::exception{
    std::string msg;
    public:
        explicit Exception(const std::string &message):msg(message){}
        virtual std::string what(){return msg;}
};

class Person{
    public:    
        int age;
        std::string name;
        
        Person(){}
        virtual void putdata() = 0;
        virtual void getdata() = 0;
};

class Student: public Person{
    private:
        int mark[6];
        int cur_id;
    public:
        Student(){cur_id+=1;}
        
        void putdata()override{
            std::cout<<name<<" ";
            std::cout<<age<<" ";
            
            int sum = 0;
            for(int i =0; i<6; i++){
                sum += mark[i];
            }
            std::cout<<sum<<" ";
            std::cout<<cur_id<<" ";
        }
        void getdata()override{
            std::cin>>name;
            std::cin>>age;
            
            for(int i = 0; i<6; i++){
                std::cin>>mark[i];
            }
            try{
                for(int i = 0; i<6; i++){
                    if(mark[i]>100 || mark[i]<0) throw Exception("invalid mark.");
                }
            }catch(Exception &e){
                std::cerr<<e.what()<<std::endl;
            }
        }
};

class Professor: public Person{
    private:
        int publications;
        int cur_id;
        
    public:
        Professor(){cur_id+=1;}
        void putdata()override{
            std::cout<<name<<" ";
            std::cout<<age<<" ";
            std::cout<<publications<<" ";
            
        }
        void getdata()override{
            std::cin>>name;
            std::cin>>age;
            std::cin>>publications;
            try{
                if(age>80||age<0) throw Exception("invalid age");
                if(publications<=0|| publications>1000) throw Exception("invalid publication");
            }catch(Exception &e){
                std::cerr<<e.what()<<std::endl;
            }
        }
};
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

