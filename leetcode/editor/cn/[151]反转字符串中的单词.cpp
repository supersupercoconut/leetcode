#include "../../../stdc.h"
using namespace std;

namespace solution151{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 对于一个字符串 应该先对其进行空格的去除(使用双指针)，再后续处理
    void remove_space(string& s)
    {
        int left = 0;
        int right = 0;
        while(right < s.size())
        {
            // 将开始的所有空格或者单词之间可能存在的空格全部删除 | 这种逻辑会使字符串最后可能有一个空格残留
            if( ( right>0 && s[right]==' ' && s[right-1]==' ') || (right == 0 && s[right]==' ') )
                right++;
            else
                s[left++] = s[right++];
        }
        if(left == 0) s.resize(0);  // 字符串全部为空格
        else
        {
            // 在前面去除字符串空格的逻辑中 | 字符串前面的空格会有一个保留(加了一个辅助的判断来处理) | 字符串后面的空格也会被保留一个(这里的处理直接去看字符串结尾的字符就好)
                // 前面已经判断了 left不会小于1
            if(s[left-1] == ' ')
                s.resize(left-1);
            else
                s.resize(left);
        }
    }



    string reverseWords(string s)
    {
        if(s.empty()) return 0;
        remove_space(s);
        // 整体反转
        reverse(s.begin(), s.end());

        // 这里使用迭代器完全是想要使用reverse这个函数
        auto left = s.begin();
        auto right = s.begin();
        for(; right!=s.end(); ++right)
        {
            if(*right == ' ')
            {
                reverse(left,right);
                left = right+1;
            }
        }
        // 退出循环,最后一个单词没有旋转(所以手动再反转 | 而且我觉得在for循环里面判断right是否快到s.end()了有点不对)
        reverse(left,s.end());
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution151;
int main() {
    Solution solution = Solution();
    string a= "hello world";
    solution.reverseWords(a);
    return 0;
}
