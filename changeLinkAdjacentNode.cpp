/*
*��һ������ĵ�һ�͵ڶ����������������͵��ĸ����������Դ�����
*author �� ����
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
{//ע������һ��Ҫ�����ò���
    if(NULL==head||NULL==head->pNext)
        return;
    Node* pre=NULL;
    Node* p=head;
    Node* q=head->pNext;
    while(p!=NULL&&q!=NULL)
    {//��ͷ��㵥������
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
    //������������
    changeLinkAdjacentNode(test1);
    printLink(test1);
    //����ż������
    changeLinkAdjacentNode(test1);
    Node *tmp=new Node();
    tmp->value=5;
    tmp->pNext=NULL;
    p->pNext=tmp;
    printLink(test1);
    changeLinkAdjacentNode(test1);
    printLink(test1);
}