/*
* ���ܣ��������в������������С�����Ƚϴ���o��1.5n����
* ˼·���Ȱ����ڵ��������Ƚ��£�Ȼ���ĺ�max�Ƚϣ�С������min�Ƚ�
*author�� ����
*date �� 2014-05-13
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
            {//iλ�ǽ�С����i+1λ�ǽϴ���������iλ�Ƚ�min��i+1�Ƚ�max
                if(v[i]<min)
                    min=v[i];
                if(v[i+1]>max)
                    max=v[i+1];
            }
            else
            {//����i+1�ǽ�С������i+1�Ƚ�min��i�Ƚ�max
                if(v[i+1]<min)
                    min=v[i+1];
                if(v[i]>max)
                    max=v[i];
            }
        }
        else
        {//���ֻ��һ������
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