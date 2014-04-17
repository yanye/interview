#include <iostream>
using namespace std;
#define MAX 6
void PrintArray(int arr[], int n)
{
   for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int BinarySearch(int arr[], int begin,int end,int key)
{
  if(NULL==arr)
    throw "Invalid arguments";
  if(begin>end)
    return -1;
  int middle;
  while(begin<=end)
  {
    middle=begin+(end-begin)/2;
    if (arr[middle]==key)
      return middle;
    else if (arr[middle]<key)
      begin=middle+1;
    else
      end=middle-1;
  }
  return -1;
}
int CycleSearch(int arr[],int begin,int end,int key)
{
  if(NULL==arr)
    throw "Invalid arguments";
  if(end<begin)
    return -1;
  int middle=begin+(end-begin)/2;
  if(arr[middle]>=arr[begin])
  {
    if(key<=arr[middle]&&key>=arr[begin])
      return BinarySearch(arr,begin,middle,key);
    else
    {
      return CycleSearch(arr,middle+1,end,key);
    }
  }
  else
  {
    if(key<=arr[end]&&key>=middle)
      return BinarySearch(arr,middle,end,key);
    else
    {
      return CycleSearch(arr,begin,middle-1,key);
    }
  }
}
void main(int argc, char* argv[])
{
  int arr[MAX]={5,7,9,1,3,4};
  PrintArray(arr,MAX);
  cout<<CycleSearch(arr,0,MAX-1,9);
}