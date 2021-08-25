// search algorithms 

# include <iostream>

template <typename T>
int sequential_search(const T list[], int length, const T &item){
	int loc;
	bool found = false;
	
	for(loc = 0; loc<length; loc++){
		if(list[loc] == item){
			found = true;
			break;
		}
	}
	
	if(found) return loc;
	return -1;
}

template <typename T>
int binary_search(const T list[], int length, const T &item){
	int first  = 0;
	int last =  length -1;
	int mid;
	
	bool found = false;
	while(first <= last && !found){
		mid = (first + last)/2;
		
		if(list[mid] == item) found = true;
		else if(list[mid] > item) last = mid -1;
		else first = mid + 1;
	}
	
	if(found) return mid;
	return -1;
}
