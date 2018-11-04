#include <iostream>
#include <algorithm>


template <typename T>
void __shifDown(T arr[],int i,int n)
{
  while(2*i+1 < n) {
    auto j = 2*i+1;
    if(j+1 < n && arr[j] < arr[j+1])
      j += 1;
    if(arr[i] >= arr[j])
      break;
    std::swap(arr[i],arr[j]);
    i = j;
  }
}


template <typename T>
void HeapSort(T arr[],int n)
{
  for(int i = (n-1)/2; i >= 0; i--)
    __shifDown(arr,i,n);

  for(int i = n -1; i > 0; i--){
    std::swap(arr[0],arr[i]);
    __shifDown(arr,0,i);
  }
}
