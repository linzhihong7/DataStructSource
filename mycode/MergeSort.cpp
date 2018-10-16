#include <iostream>
#include <algorithm>
template <typename T>
void __merge(T arr[],int l,int mid,int r)
{
  T aux[r-l+1];

  for(int i = l;i <= r; i++)
    aux[i-l] = arr[i];

  int i = l, j = mid + 1;
  for(int k = l; k <= r; k++){
    if(i > mid){
      arr[k] = aux[j-l];
      j++;
    }
    else if (j > r){
      arr[k] = aux[i-l];
      i++;
    }
    else if(aux[i-l] < aux[j-l]) {
      arr[k] = aux[i-l];
      i++;
    }
    else {
      arr[k] = aux[j-l];
      j++;
    }
  }

}
//From Top to Down
template <typename T>
void __mergeSort(T arr[],int  l,int  r)
{
  if( l == r)
    return;
  /*if(r -l <= 15){ //second optimisation, insertionSort is faster than  MergeSort when you use a short array
    insertionSort(arr,l,r);
    return;
  }*/
  int mid = (l+r)/2;
  __mergeSort(arr,l,mid);
  __mergeSort(arr,mid+1,r);
  if(arr[mid] > arr[mid+1]) //firsh optimisation
    __merge(arr,l,mid,r);

}
template <typename T>
void  MergeSort(T arr[],int n)
{
  __mergeSort(arr,0,n-1);
}
template <typename T>
T  min(T a,T b)
{
  return a<b ? a : b;
}
template <typename T>
void MergeSortBU(T arr[],int n)
{
  for(int sz = 1; sz <= n; sz+=sz)
    for(int i = 0;  i+sz < n; i += sz + sz)
       __merge(arr,i,i+sz-1,min(i+2*sz-1,n-1));

}



int main(int argc, char const *argv[]) {
  int v1[10] = {10,9,8,7,6,5,4,3,2,1};
    MergeSortBU(v1,10);

    for (auto &i : v1)
      std::cout << i << " ";
    std::cout << std::endl;

  return 0;
}
