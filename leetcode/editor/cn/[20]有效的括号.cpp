#include "../../../stdc.h"

using namespace std;

namespace solution20{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 使用栈来判断是不是一个括号匹配的情况 | 难道不是想成功匹配上的括号字符串都是对称的么
    /*
     * 1. 之前的想法是基于所有能够成功匹配的字符串都是对称的 但是(){}[]这种字符串也是对称的，所以这种思路不成立
     * 2. 如果不使用栈而是使用map来是实现功能的话，简单的逻辑就是能实现左/右括号在数量上面的一致
     *      其实这里是左括号还是右括号来入栈都是没有问题的 代码随想录上使用的是右入栈，我这里实现的是左入栈
     *
     * */
    bool isValid(string s){
        // 根据题目中的要求 空字符串也是true
        if(s.empty())
            return true;
        if(s.size()%2 != 0)
            return false;
        stack<int> left;
        //进行字符串的遍历 -> 如果是左括号就入栈 右括号就出栈
        for(int i = 0; i<s.size(); ++i){
            if(s[i] == '{' || s[i] == '[' || s[i] == '(' ) left.push(s[i]);
            else
            {
                // 这里将左括号入栈就是比右括号稍微复杂一点 | 并且 将left.size()的条件先写出来，可以防止left为空的时候，还对left使用top这个函数，这样会导致对一个空栈的访问，会导致错误
                if(left.size() != 0 && (
                        (left.top() == '{' && s[i] == '}') ||
                        (left.top() == '(' && s[i] == ')') ||
                        (left.top() == '[' && s[i] == ']') ))
                    left.pop();
                else
                    return false;

            }

        }

        // 已经结束了，但是左括号还是多
        if(left.size() != 0) return false;
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution20;
int main() {
    Solution solution = Solution();
    cout<<solution.isValid("){");
    return 0;
}
