#include <iostream>
#include <algorithm>

template <typename Item>
class MaxHeap {
public:
  MaxHeap(int cap) : capacity(cap),count(0),data(new Item[cap+1]) { }
  MaxHeap(Item arr[],int n);
  bool  IsEmpty() { return count == 0; }
  int   size()    { return count; }
  void  insert(Item);
  Item  extractMax();


private:
  void  ShiftUp();
  void  ShitDown();
  Item *data;
  int  capacity;
  int  count;
};

void  MaxHeap::insert(Item item)
{
  assert(count <= capacity);
  data[count+1] = item;
  count++;
  ShiftUp(count);
}

Item  MaxHeap::extractMax()
{
    auto ret = data[1];
    std::swap(data[1],data[count]);
    count--;
    ShiftDown(1);
}

void  MaxHeap::ShiftUp(int k)
{
  while(data[k] > data[k/2] && k > 1) {
    std::swap(data[k],data[k/2]);
    k /= 2;
  }
}

void  MaxHeap::ShiftDown(int k)
{
  while(2*k <= count) {
    int j = 2*k

    if(j+1 <= count && data[j+1] > datat[j])
      j += 1;

    if(data[k] >= data[j])
      break;

     std::swap(data[j],data[k]);
     k = j;
  }
}

MaxHeap::MaxHeap(Item arr[],int n)
{
  data = new Item[n+1];
  capacity = n;

  for(int i = 0; i < n; i++)
    data[i+1] = arr[i];
  count = n;

  for(int i = count/2; i >= 1; i--)
    ShiftDown(i);
}

template <typename Item>
void  HeapSort1(Item arr[],int n)
{
  MaxHeap<Item> maxheap(n+1);
  for(int i = 0; i < n; ++i)
    maxheap.insert(arr[i]);

  for(int i = n - 1; i >= 0; --i)
    arr[i] = maxheap.extractMax();
}

template <typename Item>
void  HeapSort2(Item arr[],int n)
{
  MaxHeap<Item> maxheap(arr,n);

  for(int i = n - 1; i >= 0; --i)
    arr[i] = maxheap.extractMax();
}
