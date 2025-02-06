//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution151{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void trans(string & s, int left, int right)
    {
        while(left < right)
        {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }

    string reverseWords(string s)
    {
        // 反转字符串中的每个单词
        int left = 0;
        while(s[left] == ' ') ++left;
        // 先使用双指针对中间空格进行去除(无法保留单词之间的一个空格)
        int slow = left;
        int fast = left;
        // note这里可以修改双指针赋值的情况，只需要认为出现多空格的时候fast前进就好了
        for(; fast < s.size(); ++fast)
        {
            if(fast >= 1 && s[fast] == ' ' && s[fast-1] == s[fast]) continue;
            else
                s[slow++] = s[fast];
        }

        // note 该问题最为复杂的部分就是如何判断什么时候s字符串的substr应该截取到哪里为止 这里极有可能出问题！！！
        if(slow > 0 && s[slow - 1] == ' ') s = s.substr(left,  slow - left - 1);
        else
          s = s.substr(left,  slow - left);

        trans(s, 0, s.size()-1);
        // 剩余对单词之间进行单独转换
        slow = 0;
        fast = 0;
        while(fast < s.size())
        {
            if(s[fast] == ' ')
            {
                trans(s, slow, fast-1);
                // slow这种定义可以保留一个空格
                slow = fast + 1;
            }
            ++fast;
        }
        // 最后一个单词没有反转 - right这里对应的最后一个正常字符
        trans(s, slow, fast-1);
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution151;
int main() {
    Solution solution = Solution();

    return 0;
}

