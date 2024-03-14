#include <iostream>
#include <string>
using namespace std;

//  替换元素 思路是使用双指针 | 从后往前进行替换
int main()
{
    string s;
    cin>>s;
    // 相当于没有重新申请一个string字符串，而是直接在原始字符串的基础上进行修改 | 从字符串的前面开始修改的话对应的时间复杂度都太高了
    int count = 0;
    for(auto i : s)
    {
        if(i >= '0' && i <= '9')
            count++;
    }
    // 判断有没有在s中找到数字
    if(count == 0) cout<<s;
    else
    {
        int left = s.size();
        // 重新设置s的大小
        s.resize(s.size()+count*5);
        int right = s.size();
        while(left < right)
        {
            if(s[left] < '0' || s[left]>'9') s[right--] = s[left];
            else
            {
                s[right--] = 'r';
                s[right--] = 'e';
                s[right--] = 'b';
                s[right--] = 'm';
                s[right--] = 'u';
                s[right--] = 'n';
            }
            left--;
        }
        cout << s;
    }
    return 0;
}
