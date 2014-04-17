#include <iostream>
using namespace std;
#define MAX_LENGTH 6

void print(int arr[],int length)
{
  for(int i=0;i<length;i++)
  {
    cout<<arr[i]<<"\t";
  }
  cout<<endl;
}
int max(int a,int b)
{
  return a>=b?a:b;
}
int MaxSubSum(int arr[],int length)
{
  if(length<1||NULL==arr)
    throw "Invalid arguments";
  int start=arr[length-1];
  int all=arr[length-1];
  for(int i=length-2;i>=0;i--)
  {
    start=max(arr[i],arr[i]+start);
    all=max(start,all);
  }
  return all;
}
void main(int argc, char* argv[])
{
  int arr[MAX_LENGTH]={-1,-2,-3,-5,-3,-2};
  print(arr,MAX_LENGTH);
  cout<<"the max sub array sum is: "<<MaxSubSum(arr,MAX_LENGTH)<<endl;
}