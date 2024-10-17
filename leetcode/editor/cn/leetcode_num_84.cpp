#include "../../../stdc.h"

using namespace std;

namespace solution84{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int res = 0; // 手动最小值
    stack<int> my_stack = {};
    /* 本问题最困难的部分并不是单调栈的实现而是最终的实现思路
     *  (1) 更小元素实现的单调栈
     *  (2) 在数组元素两侧加入0, 更方便计算整个大小 —— 如果直接使用单调栈, 输入一个递增数组，不会出现返回值
     * */
    void traversal(vector<int>& heights)
    {
        // 栈中还是保留序号
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        my_stack.push(0);

        for(int i = 1; i < heights.size(); ++i)
        {
            if(heights[i] >= heights[my_stack.top()])
                my_stack.push(i);
            else
            {
                // 小于则直接处理
                while( !heights.empty() && heights[i] < heights[my_stack.top()])
                {
                    int mid_value = heights[my_stack.top()];
                    my_stack.pop();
                    if(!my_stack.empty())
                    {
                        // 模拟的是42雨水的情况，计算的是两个边界中间位置的矩形大小
                        int left = my_stack.top();
                        int temp = (i - 1 - left) * mid_value;
                        res = temp > res ? temp : res;
                    }
                }
                my_stack.push(i);
            }
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        traversal(heights);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution84;
int main() {
    Solution solution = Solution();

    return 0;
}
