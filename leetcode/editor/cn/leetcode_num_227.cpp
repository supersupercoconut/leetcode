#include "../../../stdc.h"

using namespace std;


//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 
//
// 整数除法仅保留整数部分。 
//
// 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2³¹, 2³¹ - 1] 的范围内。 
//
// 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "3+2*2"
//输出：7
// 
//
// 示例 2： 
//
// 
//输入：s = " 3/2 "
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：s = " 3+5 / 2 "
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开 
// s 表示一个 有效表达式 
// 表达式中的所有整数都是非负整数，且在范围 [0, 2³¹ - 1] 内 
// 题目数据保证答案是一个 32-bit 整数 
// 
//
// Related Topics 栈 数学 字符串 👍 821 👎 0


namespace solution227{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 自己实现双栈解决方法比较复杂, 先更换成单栈的处理逻辑进行实现(后面的这种思路非常简单 很清晰！！)
        // 注意可能出现的负号 即开头放一个'0'
        // 其实我自己实现的逻辑与这种方法类似，只不过在处理string上面的数据上要欠缺一些
        // 补充: 如何出现空格以及括号问题应该如何操作(有一个很好的解决思路是直接使用递归来解决括号) 空格是可以直接跳过的

    stack<int> num;  //存贮数字
    stack<char> op;  //存贮操作

    // 当前函数为读取
    void eval()
    {
        // 避免元素数量不够的时候执行操作
        if(num.size() < 2) return ;

        int a = num.top();
        num.pop();
        int b = num.top();
        num.pop();
        auto tmp = op.top();
        op.pop();
        switch (tmp) {
            case '+':
            {
                num.push(b + a);
                break;
            }
            case '-':
            {
                num.push(b - a);
                break;
            }
            case '*':
            {
                num.push(b * a);
                break;
            }
            case '/':
            {
                num.push(b / a);
                break;
            }
            default:
            {
                cout << "Warning !!!" << endl;
            }
        }
    }


    int calculate(string s)
    {
        // 定义运算符的优先级
        unordered_map<char, int> mp;
        mp['+'] = 0;
        mp['-'] = 0;
        mp['*'] = 1;
        mp['/'] = 1;

        // 滤除字符串中多余的空格
        int slow = 0;
        int fast = 0;
        while(fast < s.size())
        {
            if(s[fast] != ' ')
                s[slow++] = s[fast];
            ++fast;
        }
        s = s.substr(0, slow);

        for(int i = 0; i < s.size(); ++i)
        {
            int count = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9')
            {
                count = count * 10 + (s[i] - '0');
                ++i;
            }
            // 当前字符为运算符并且num中保存了一个数字
            num.push(count);

            if(i != s.size())
            {
                // note 注意这里对应的操作, 只有当前栈中对应的操作优先级更高才需要提前处理, 无论处理与否当前的这种操作数也需要放入栈中
                // 并且这里的优先级如果相同, 也得先去处理前面 ！！ 比如 1-2-56 如果先处理后面的减号就会变成 1 - (-54) 最后结果就会变为53 | 并且这里一定是要写成while就类似与单调队列,要求前面能前一步处理的计算都先进行处理
                // 一定是 while(!op.empty() && mp[op.top()] >= mp[s[i]]) 而不是 if(!op.empty() && mp[op.top()] >= mp[s[i]])
                while(!op.empty() && mp[op.top()] >= mp[s[i]])
                    eval();
                op.push(s[i]);
            }
        }

        // 所有数字被读取完毕
        while(!op.empty())
            eval();

        cout << num.top() << endl;
        return num.top();

    }

//    // 运算符的优先级比较
//    unordered_map<char, int> m_map;
//    // 由于其保留了加减乘除，不用考虑空格来进行处理
//    int calculate(string s)
//    {
//        m_map['+'] = 0;
//        m_map['-'] = 0;
//        m_map['*'] = 1;
//        m_map['/'] = 1;
//        stack<int> s1;
//        stack<char> s2;
//        // 对字符串清理空格
//        int slow = 0;
//        int fast = 0;
//        while(fast < s.size())
//        {
//            if(s[fast] != ' ')
//                s[slow++] = s[fast];
//            ++fast;
//        }
//        s = s.substr(0, slow);
//
//        // 双栈获取数据
//        int i = 0;
//        int last = 0;
//        while(i < s.size())
//        {
//
//            if(s[i] < '0' || s[i] > '9' || s.size() - i == 1)
//            {
//                // 获取数字以及获取当前的操作数
//                auto tmp = s.substr(last, i - last);
//                s1.push(stoi(tmp));
//                // 判断当前的操作数是否为空
//                if(s2.empty()) s2.push(s[i]);
//                else
//                {
//                    if(m_map[s[i]] < m_map[s2.top()] && m_map[s2.top()] == 1)
//                    {
//                        auto a = s1.top();
//                        s1.pop();
//                        auto b = s1.top();
//                        s1.pop();
//
//                        if(s[i] == '*') s1.push(a*b);
//                        else
//                            s1.push(a/b);
//                    }
//                    // 保证是符号才能被s2读取
//                    if(s[i] < '0' || s[i] > '9') s2.push(s[i]);
//                }
//                last = i+1;
//            }
//            ++i;
//        }
//
//        // 最终都是+-元素之间的比较
//        while(!s1.empty() && !s2.empty())
//        {
//            auto a = s2.top();
//            s2.pop();
//            auto b = s1.top();
//            s1.pop();
//            auto c = s1.top();
//            s1.pop();
//
//            if(a == '+')
//                s1.push(a + b);
//            else if(a == '-')
//                s1.push(a - b);
//        }
//
//        return s1.top();
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution227;
int main() {
    Solution solution = Solution();
    solution.calculate("1*2-3/4+5*6-7*8+9/10");


    return 0;
}
