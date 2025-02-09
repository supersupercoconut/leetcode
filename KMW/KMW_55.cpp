#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::cin;

// note 实际的操作流程是借鉴了 leetcode151中的思路 先反转整体的字符串，再按照设定的字符进行反转(类似的左转字符串也是类似的处理思路)
void reverse(string& s, int start, int end)
{
  while (start < end)
  {
    std::swap(s[start], s[end]);
    ++start;
    --end;
  }
}

int main()
{
  string s;
  int n;
  cin >> n;
  cin >> s;
  reverse(s, 0, s.size()-1);
  reverse(s,0,n-1);
  reverse(s,n,s.size()-1);
  cout << s << endl;
  return 0;
}
