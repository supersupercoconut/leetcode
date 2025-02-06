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
//            char temp = s[right];
//            s[right] = s[left];
//            s[left] = temp;
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

        if(s[slow] == ' ')
            s.substr(left,  slow-1);
        else
            s.substr(left,  slow);

//        while(fast < s.size())
//        {
//            if(s[fast] != ' ')
//            {
////                if(fast - slow == 1) ++slow;
//                swap(s[slow], s[fast]);
//                ++slow;
//            }
//                ++fast;
//        }
//        cout << "|" << s << "|" << endl;

        int right = s.size()-1;
        trans(s, left, right);
        // 剩余对单词之间进行单独转换
        slow = left;
        fast = left;
        while(fast < right)
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
        trans(s, slow, fast);
        // 取字符串即删除掉左右的多余空格
//        auto res = s.substr(left, right - left + 1);
//        cout << "|" << res << "|" << endl;
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

