//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution739{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /** 这里使用单调栈/单调队列都是能处理的，只是没有想起来存放数据的时候要存放数据的下标！！！ 这样可以简化不少难度 **/
    vector<int> res = {};
    stack<int> mystack = {};

    void traversal(vector<int>& temperatures)
    {
        mystack.push(0);
        res.assign(temperatures.size(), 0);
        // 遍历当前数组
        for(int i = 0; i < temperatures.size(); ++i)
        {
            if(temperatures[mystack.top()] > temperatures[i] || temperatures[mystack.top()] == temperatures[i])
                mystack.push(i);
            else
            {
                /* 只需要单独执行就ok */
                while(!mystack.empty() && temperatures[mystack.top()] < temperatures[i])
                {
                    res[mystack.top()] = i - mystack.top();
                    mystack.pop();
                }
                mystack.push(i);
            }
        }
    }

    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        if(temperatures.empty()) return {};
        traversal(temperatures);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution739;
int main() {
    Solution solution = Solution();

    return 0;
}

