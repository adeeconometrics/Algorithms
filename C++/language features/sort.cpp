// sort 
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 // sort
 void selection_sort(int arr[], int size){
	 int min_idx, min;
	 for(int i = 0; i<size-1; i++){
	 	min_idx = i;
	 	for(int j = i+1; j<size; j++){
	 		if(arr[j]<arr[min_idx]){
	 			min_idx = j;
	 			// swap 
	 			min = arr[min_idx];
	 			arr[min_idx] = arr[i];
	 			arr[i] = min;
			 }
		 }
	 }
 }
 
 int main(){
 	int arr[5];
 	cout<<"enter array of length 5 \n";
 	for(int i = 0; i<5; i++){
 		cout<<"arr["<<i+1<<"]: ";
 		cin>>arr[i];
	 }
	 
	 // display
 	for(int i = 0; i<5; i++){
 		cout<<"arr["<<i+1<<"]: "<<arr[i]<<endl;
	 }
 }
