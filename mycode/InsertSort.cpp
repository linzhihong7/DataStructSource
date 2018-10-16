#include <iostream>
#include <algorithm>

template<typename T>
void  InsetSort(T arr[],int n)
{
  for( int i = 1; i < n; ++i) {
    int curr = i;
    for( int j = i - 1; j >= 0; --j)
      if( arr[curr] < arr[j] ){
        std::swap(arr[curr],arr[j]);
        curr = j;
      }
  }

}

int main(int argc, char const *argv[]) {
int v1[10] = {10,9,8,7,6,5,4,3,2,1};
  InsetSort(v1,10);

  for (auto &i : v1)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
