#include "../../../stdc.h"
using namespace std;
namespace solution42{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*** 思路: 想依靠单调栈计算实际形成水池的两个边界, 将这个边界提取出来，即可以计算中间部分存储的雨水高度
     *      (1) 实际上是按照行进行计算的水池容积 左右边界的小值减去中间值再乘以宽度即可以完成计算 —— 每一次计算都是计算左右边界一行的容量值
     *   ***/

    // 构建整体的递归栈
    int res = 0;
    stack<int> my_stack = {};

    void traversal(vector<int>& height)
    {
        // 方便前后插入元素
        deque<int> my_vector = {};
        my_stack.push(0);
        for(int i = 1; i < height.size(); ++i)
        {
            if(height[my_stack.top()] >= height[i])
                my_stack.push(i);
            else
            {
                while(!my_stack.empty() && height[my_stack.top()] < height[i])
                {
                    // 当前如果能弹出元素 —— 那么其右边界一定已知, 左边界就是当前元素在栈中的前一个元素
                    int mid = my_stack.top();
                    my_stack.pop();
                    // 寻找左侧边界，同时对于这个左侧没有更大数值的元素，进行跳过
                    if(my_stack.empty()) break;
                    int left = my_stack.top();
                    int min_value = height[left] > height[i] ? height[i] : height[left];
                    res += (min_value - height[mid]) * (i-left-1);
                    cout << res << ' ';
                }
                my_stack.push(i);
            }
        }
    }

    int trap(vector<int>& height)
    {
        if(height.empty()) return 0;
        traversal(height);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution42;
int main() {
    Solution solution = Solution();
    vector<int> height = {4,2,0,3,2,5};
    solution.trap(height);
    return 0;
}
