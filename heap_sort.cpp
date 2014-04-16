#include <iostream>
using namespace std;
#define MAX_LENGHT 10
//从pos位置处调整大根堆
void print(int arr[],int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
void HeadAdjust(int arr[],int pos, int length)
{
  int tmp=arr[pos];
  int child=2*pos+1;
  while(child<length)
  {
      if(child+1<length&&arr[child]<arr[child+1])
      {
         child=child+1;
      }
      if(arr[pos]<arr[child])
      {
        arr[pos]=arr[child];
        pos=child;
        child=pos*2+1;
        arr[pos]=tmp;
      }
      else
        break;
  }
  print(arr,length);
}
void BuildMaxHeap(int arr[], int length)
{
  for(int i=length/2-1;i>=0;i--)
  {
    HeadAdjust(arr,i,length);
  }
}
void main(int argc, char* argv[])
{
  int arr[MAX_LENGHT]={9,5,7,8,3,6,44,55,1,2};
  print(arr,MAX_LENGHT);
  BuildMaxHeap(arr,10);
  for(int i=MAX_LENGHT-1;i>0;i--)
  {
    int tmp=arr[0];
    arr[0]=arr[i];
    arr[i]=tmp;
    HeadAdjust(arr,0,i);
  }
  print(arr,MAX_LENGHT);
}