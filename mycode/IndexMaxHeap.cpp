#include <iostream>
#include <algorithm>

template <typename Item>
class IndexMaxHeap {
public:
  MaxHeap(int cap) : capacity(cap),count(0),data(new Item[cap+1]),index(new int[cap+1]) { }
  MaxHeap(Item arr[],int n);
  ~MaxHeap() {
    delete []data;
    delete []index;
  }
  bool  IsEmpty() { return count == 0; }
  int   size()    { return count; }
  void  insert(Item);
  Item  extractMax();


private:
  void  ShiftUp();
  void  ShitDown();
  Item *data;
  int  *index;
  int  capacity;
  int  count;
};

void  IndexMaxHeap::insert(Item item,int i)
{
  assert(count + 1 <= capacity);
  assert(i + 1 <= capacity && i + 1 >= 1);
  i += 1;
  index[count+1] = i;
  data[i] = item;
  count++;
  ShiftUp(count);
}

Item  IndexMaxHeap::extractMax()
{
    auto ret = data[index[1]];
    std::swap(index[1],index[count]);
    count--;
    ShiftDown(1);
    return  ret;
}

int  IndexMaxHeap::extractMaxIndex()
{
    auto ret = index[1];
    std::swap(index[1],index[count]);
    count--;
    ShiftDown(1);
    return ret;
}
void  IndexMaxHeap::ShiftUp(int k)
{
  while(data[index[k]] > data[index[k/2]] && k > 1) {
    std::swap(index[k],index[k/2]);
    k /= 2;
  }
}

void  IndexMaxHeap::ShiftDown(int k)
{
  while(2*k <= count) {
    int j = 2*k

    if(j+1 <= count && data[index[j+1]] > datat[index[j])
      j += 1;

    if(data[k] >= data[j])
      break;

     std::swap(index[j],index[k]);
     k = j;
  }
}

Item getItem(int i) {
  return data[i+1];
}

void change(int i,Item newItem)
{
  i += 1;
  data[i] = newItem;
  for(int j = 1;j <= count; j++)
    if(index[j] == i) {
      ShiftUp(j);
      ShiftDown(j);
    }
}

MaxHeap::IndexMaxHeap(Item arr[],int n)
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
