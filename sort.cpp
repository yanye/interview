#include "sort.h"
void swapint(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void printArray(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}
void StraightInsertSort(int a[],int size)
{
	if(size<=0)
	{
		cout<<"the size need to be more than 0"<<endl;
		return;
	}
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j>=0;j--)
		{
			if(a[j]<a[j-1])
			{
				swapint(a[j-1],a[j]);
			}
			else
			{
				break;
			}
		}
	}
}
void testStraightInsertSort()
{
	int a[]={4,3,2,1};
	int num=4;
	cout<<"Original order is : ";
	printArray(a,num);
	StraightInsertSort(a,num);
	cout<<"Straight insert sort is :";
	printArray(a,num);
}