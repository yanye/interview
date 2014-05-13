/*
*将一个链表的第一和第二个数交换，第三和第四个数交换，以此类推
*author ： 严烨
*date : 2014-05-13
*/
#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node* pNext;
};
void printLink(Node* head)
{
    Node *p=head;
    while(p)
    {
        cout<<p->value<<" -> ";
        p=p->pNext;
    }
    cout<<"End"<<endl;
}
void changeLinkAdjacentNode(Node * &head)
{//注意这里一定要是引用才行
    if(NULL==head||NULL==head->pNext)
        return;
    Node* pre=NULL;
    Node* p=head;
    Node* q=head->pNext;
    while(p!=NULL&&q!=NULL)
    {//对头结点单独处理
        if(p==head)
            head=q;
        else
            pre->pNext=q;
        p->pNext=q->pNext;
        q->pNext=p;
        pre=p;
        p=p->pNext;
        if(p!=NULL)
            q=p->pNext;
    }
}
int main(int argc,char** argv)
{
    Node* test1;
    test1=new Node();
    test1->value=0;
    Node* p=test1;
    for(int i=1;i<5;++i)
    {
        Node *tmp=new Node();
        tmp->value=i;
        p->pNext=tmp;
        p=tmp;
    }
    p->pNext=NULL;
    printLink(test1);
    //测试奇数个数
    changeLinkAdjacentNode(test1);
    printLink(test1);
    //测试偶数个数
    changeLinkAdjacentNode(test1);
    Node *tmp=new Node();
    tmp->value=5;
    tmp->pNext=NULL;
    p->pNext=tmp;
    printLink(test1);
    changeLinkAdjacentNode(test1);
    printLink(test1);
}