#include <iostream>
#include <assert.h>
using namespace std;
void *Memcpy(void* dest,const void* src,size_t size)
{
  assert((NULL!=src)&&(NULL!=dest)&&(size>0));
  char* pSrc;
  char* pDest;
  if(src<dest&&(char*)src+size>(char*)dest)
  {//内存有覆盖情况，从后往前拷贝
    pSrc=(char*)src+size-1;
    pDest=(char*)dest+size-1;
    while(size>0)
    {
      *pDest--=*pSrc--;
      size--;
    }
  }
  else
  {
    pSrc=(char*)src;
    pDest=(char*)dest;
    while(size>0)
    {
      *pDest++=*pSrc++;
      size--;
    }
  }
  return dest;
}
void main(int argc, char** argv)
{
  char testchar[100]="abcdefghijk";
  cout<<"original sequence is: "<<testchar<<endl;
  Memcpy(testchar+2,testchar,5);
  cout<<"copy sequences is: "<<testchar+2<<endl;
  cout<<"full sequences is: "<<testchar<<endl;

}