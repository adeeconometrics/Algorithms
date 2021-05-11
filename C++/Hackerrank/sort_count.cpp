#include <iostream>
static int x = 0;

void sort(int *a, int *b, int n){
  //intialize values
  int t; 
  int count[x+1];
  
  for(int i = 0; i<x; i++)
    count[i] = 0;
  
  //count the occurance of the elements
  for(int i = 0; i<n; i++){
    t = a[i];
    count[t]++;
  }
  
  //update count of the array
  for(int i = 1; i<=x; i++)
    count[i] = count[i] + count[i-1];
  
  //add and decrement the values
  for(int i = 0; i<n; i++){
    t = a[i];
    b[count[t]] = t;
    count[t] = count[t-1];
  }
}

int main(){
  int n;
  int a[100], b[100];
  int *ptr_a = a, *ptr_b = b;
  
  std::cout<< "Enter size of the array: ";
  std::cin>> n;
  
  for(int i = 0; i<n ; i++){
    std::cin>> a[i];
    if(a[i] > x) x = a[i];
  }
  
  sort(ptr_a, ptr_b,n);
  
  //output
  for(int i = 0; i<n; i++){
    t = a[i];
    b[count[t]] = t;
    count[t] = count[t] - 1;
  }
}
