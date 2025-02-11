// 对字符串中的数字进行替换成为number
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    // note 常见的数组扩容分析，一般是先进行数据扩容再从后往前分析，将O(n^2)变为O(n)
    int count = 0;
    int count_number = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
            ++count;
        else
            ++count_number;
    }

    // resize处理字符串, 并且使用双指针进行字符串的处理
    int slow = str.size() - 1;
    str.resize(count_number + count * 6);
    int fast = str.size() - 1;
    for(; slow >= 0; --slow)
    {
        if(str[slow] >= '0' && str[slow] <= '9')
        {
            str[fast--] = 'r';
            str[fast--] = 'e';
            str[fast--] = 'b';
            str[fast--] = 'm';
            str[fast--] = 'u';
            str[fast--] = 'n';
        }
        else
        {
            // 是数字即插入数据
            str[fast--] = str[slow];
        }
    }
    cout << str;
    
    return 0;
}