#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
void SelectionSort(T arr[], int  n)
{
  for ( int i = 0 ; i != n ; ++i) {
    int  Mindex = i;
    for ( int j = i + 1; j != n ; ++j)
      if ( arr[j] < arr[Mindex])
        Mindex = j;

    std::swap(arr[i],arr[Mindex]);
  }
}

int main(int argc, char const *argv[]) {
  std::vector<int> v1 = {10,9,8,7,6,5,4,3,2,1};
  SelectionSort(v1,10);

  for (auto &i : v1)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
