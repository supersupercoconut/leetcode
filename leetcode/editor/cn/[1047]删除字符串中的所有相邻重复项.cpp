 #include "../../../stdc.h"
using namespace std;


namespace solution1047{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 刚开始没有思路，看完随想录上面的解释，觉得使用栈的方法确实好(相比与暴力的方法可以降低复杂度)
    string removeDuplicates(string s)
    {
        // 对异常情况进行处理
        if(s.empty() || s.size() == 1)
            return s;

        // 一开始自己想的逻辑都不如这个简单 | 之前就想限制谁来入栈，不如来看栈顶元素是不是与当前元素想等的思路简单
        stack<char> temp;
        for(int i = 0; i < s.size(); ++i) {
            if(!temp.empty() && temp.top() == s[i])
                temp.pop();
            else
                temp.push(s[i]);

        }

        string result;
        while(!temp.empty())
        {
            char a = temp.top();
            result += a;
            temp.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1047;
int main() {
    Solution solution = Solution();

    return 0;
}
