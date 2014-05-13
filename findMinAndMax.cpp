/*
* 功能：在数组中查找最大数和最小数，比较次数o（1.5n）；
* 思路：先把相邻的两个数比较下，然后大的和max比较，小的数和min比较
*author： 严烨
*date ： 2014-05-13
*/
#include <iostream>
using namespace std;
void findMinAndMax(int v[], int length,int &min,int &max )
{
    if(length<0||NULL==v)
        return;
    min=max=v[0];
    for(int i=0;i<length;i+=2)
    {
        if(i+1<length)
        {
            if(v[i]<=v[i+1])
            {//i位是较小数，i+1位是较大数，则在i位比较min，i+1比较max
                if(v[i]<min)
                    min=v[i];
                if(v[i+1]>max)
                    max=v[i+1];
            }
            else
            {//否则i+1是较小数，在i+1比较min，i比较max
                if(v[i+1]<min)
                    min=v[i+1];
                if(v[i]>max)
                    max=v[i];
            }
        }
        else
        {//最后只有一个数了
            if(v[i]<min)
                min=v[i];
            if(v[i]>max)
                max=v[i];
        }
    }
}
int main(int argc,char** argv)
{
    int test1[5]={5,4,3,2,1};
    int test2[6]={6,5,4,3,2,1};
    int min;
    int max;
    findMinAndMax(test1,5,min,max);
    cout<<"test1-> min: "<<min<<"  max: "<<max<<endl;
    findMinAndMax(test2,6,min,max);
    cout<<"test2-> min: "<<min<<"  max: "<<max<<endl;
    return 1;
}