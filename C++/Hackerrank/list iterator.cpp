# include <iostream>

template<typename T>
class iterator{
	public:
		using value_t = typename T::value_t;
		typedef value_t* pointer_t;
		typedef value_t& reference_t;
	private:
		pointer_t m_ptr;
		
	public:
		iterator(pointer_t ptr): m_ptr(ptr){}
		
		reference_t operator++(int){
			T* old = *this;
			++(*this);
			return old;
		}
		
		reference_t operator--(int){
			T* old = *this;
			--(*this);
			return old;
		}
		
		iterator& operator++(){
			return ++(*this);
		}
		
		iterator& operator--(){
			return --(*m_ptr);
		}
		
		reference_t operator[](int idx){
			return *(m_ptr+idx);
		}
		
		reference_t operator*(){
			return *m_ptr;
		}
		
		bool operator!=(iterator &other){
			return !(*this ==  other);
		}
};

template<typename T>
class Vector{
    private:
        int size;
        T *vec;
        int at_index = -1;
        T *at_top, *at_back;
        int growth_rate = 2;

    public:
		using value_t = T;
		typedef iterator<Vector<T>> Iterator;
        Vector(){
            at_index += 1;
            size = 1;
            vec = new T[size];
        }


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

//        ~Vector(){clear();}

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
		
		Iterator begin(){
			return Iterator(at_top);
		}
		
		Iterator end(){
			return Iterator(at_back);
		}
        void display(){
            int i = 0;
            while(i<at_index){
            	i++;
                std::cout<<vec[i]<<std::endl;
            }
            return;
        }
        
        bool isFull(){
            if(at_index == size) return true;
            return false;
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

int main(){
	Vector<int> l;
	for(int i = 0; i<10; ++i) l.add(i+1);
	
	l.display();
//	for(Vector<int>::Iterator it = l.begin(); it!=l.end(); ++it)
//		std::cout<<*it<<" ";
}
