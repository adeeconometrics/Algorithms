// vector class
# pragma once
# ifndef _VECTOR_H
# define  _VECTOR_H
template <class T>
class Vector{
    private:
        int size;
        T *vec;
        int at_index = -1;
        T *at_top, *at_back;
        int growth_rate = 2;

    public:

        Vector(){
            at_index += 1;
            size = 1;
            vec = new T[size];
        }

        // Vector(const int length){
        //     size = length;
        //     at_index += 1;
        //     vec = new T[size];
        // }

        Vector(const int rate){
            growth_rate = rate;
            at_index += 1;
            vec = new T[size];
        }

        Vector(const int length, const int rate){
            at_index += 1;
            size = length;
            vec = new T[size];
            growth_rate = rate;
        }

        ~Vector(){clear();}

        void add(const T &data){
            if(isFull()){
                //double size
                int temp_size = size;
                size *= growth_rate;
                T *temp_vec = new T[size];
                int i = 0;
                while(i<temp_size){
                    temp_vec[i] = vec[i];
                    i += 1;
                }
                vec = temp_vec;
                temp_vec = vec;
                delete[] temp_vec;

                vec[at_index] = data;
                at_index += 1;
            }
            vec[at_index] = data;
            at_index += 1;
        }
        void remove(const T data);

        /**
         * bubble sort: ascending 
        */
        void sort(){
            if(is_sortable()){
                // bubble sort
                for(int i=0; i<at_index; i++){
                    for(int j = i-1; j<i-j; j++){
                        if(vec[i]>vec[j]){
                            T temp = vec[i];
                            vec[i] = vec[j];
                            vec[j] = temp;
                        }
                    }
                }
            }
            else{
                std::cout<<"type is not sortable.";
                return;
            }
        }

        void display(){
            int i = 0;
            while(i<at_index){
                std::cout<<i<<std::endl;
            }
            return;
        }

        void clear(){
            delete[] vec;
        }

        // specialized functions
        void fit();
        void push_front(T &data);
        void pop_front();
        void push_back(T &data);
        void pop_back();

        T top(){return *at_top;}
        T back(){return *at_back}

        bool isFull(){
            if(at_index == size) return true;
            return false;
        }

        bool isElement(const T data){
            int i = 0;
            bool flag = false;
            while(i<size){
                if(vec[i] == data) flag = true;
                i += 1;
            }
            return flag;
        }

        bool isEmpty(){
            if(at_index == -1) return true;
            else return false;
        }

    private:
        bool is_sortable(T){
            return std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<T, std::string>::value;
        }
};

# endif