#include <iostream>
#include <algorithm>


template <typename T>
int  partition(T arr[],int l,int r)
{
  int j = l;
  for(int i = l + 1; i <= r; i++) {
    if(arr[i] < arr[l]){
      std::swap(arr[++j],arr[i]);

    }
  }
  std::swap(arr[j],arr[l]);

  return j;
}

template <typename T>
void  __quickSort(T arr[],int l,int  r)
{
  if(l >= r)
    return;

  int p = partition(arr,l,r);
  __quickSort(arr,l,p-1);
  __quickSort(arr,p+1,r);

}
int main(int argc, char const *argv[]) {
  int v1[10] = {10,9,8,7,6,5,4,3,2,1};
  __quickSort(v1,0,9);

  for (auto &i : v1)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
