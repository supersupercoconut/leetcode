#include "../../../stdc.h"

using namespace std;

namespace solution150{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int evalRPN(vector<string>& tokens)
    {
        if(tokens.empty())
            return 0;

        stack<string> calc;
        int result = 0;
        for(auto& i : tokens)
        {
            // 碰见数就入栈 | 碰到运算符就出栈两个数进行运算
            if(i == "+" || i == "-" || i == "/" || i == "*")
            {
                int num1 = stoi(calc.top());
                calc.pop();
                int num2 = stoi(calc.top());
                calc.pop();
                if(i == "+")
                {
                    result = num2 + num1;
                }
                else if(i == "-")
                {
                    result = num2 - num1;
                }
                else if(i == "*")
                {
                    result = num2 * num1;
                }
                else if(i == "/")
                {
                    result = num2 / num1;
                }
                // 数据再入栈
                calc.push(to_string(result));
            }
            else
                calc.push( i);
        }

        return stoi(calc.top());
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution150;
int main() {
    Solution solution = Solution();

    return 0;
}
