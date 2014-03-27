int Ustrlen(const char *strSource)
{
  // 声明变量
  int iLength(0);
  // 遍历字符串，查找字符'\0'
  while(*strSource++ != '\0')
  {
    ++iLength;
  }
  // 返回字符串的长度
  return iLength;
}
/************************************************************************/
// 函数名称: _ReversalChar
// 输入参数: strSouce，待反转字符串；iStart，旋转字符串开始位置；iEnd，旋转字符串结束位置
// 输出参数: char*，反转后字符串的指针；
// 描    述: 反转iStart到字符串iEnd之间的字符串
/************************************************************************/
char* _ReversalChar(char *strSouce,int iStart,int iEnd)
{
  // 反转字符串
  for(;iEnd > iStart; ++iStart,--iEnd)
  {
    char ch;
    ch = strSouce[iStart];
    strSouce[iStart] = strSouce[iEnd];
    strSouce[iEnd] = ch;
  }
  // 返回字符串指针
  return strSouce;
}

/************************************************************************/
// 函数名称: ReversalChar
// 输入参数: strSource，待反转字符串
// 输出参数: char*，反转字符串后的指针
// 描    述: 按单词反转字符串
/************************************************************************/
char * ReversalChar(char *strSouce)
{
  // 获取字符串的长度
  int iLength = Ustrlen(strSouce);

  // 反转整个字符串
  _ReversalChar(strSouce,0,iLength-1);

  // 声明变量（单词的开始以及结束默认从0开始）
  int iStart(0),iEnd(0);

  // 查找单词
  // 像上面讨论的查找单词的情况，我们只需要修改这部分，就可以实现对不
  // 同格式类型单词进行处理，为了更好的通用性，其实最好把查找单词这部分
  // 作为单独一个函数，或者一个类来处理
  for(int i = 0; i < iLength; ++i)
  {
    // 查找空格分割符号
    if(strSouce[i] == ' '||i==iLength-1)
    {
      // 找到一个单词
      iEnd = i-1;
      if (i==iLength-1)
      {
        iEnd=i;
      }
      // 对于只有一个字符的单词比如说（I）没有必要反转
      if(iStart < iEnd)
      {
        // 反转单词
        _ReversalChar(strSouce,iStart,iEnd);
      }
      // 记录下一个单词的开始位置
      iStart = i+1;
    }
    // 特殊处理几种常见标点符号
    else if(strSouce[i] == '!' || strSouce[i] == ',')
    {
      iStart = i+1;
    }
  }
  // 返回反转后的字符串
  return strSouce;
}
int main(int argc,char* argv[])
{
  char ch[] ="Here is www.finish.com";
  cout << "Source string: " << ch << endl;
  cout << "Reversal string: " << ReversalChar(ch) << endl;

}
