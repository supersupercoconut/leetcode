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
//    int res = 0;
//    stack<int> my_stack = {};
//
//    void traversal(vector<int>& height)
//    {
//        // 方便前后插入元素
//        deque<int> my_vector = {};
//        my_stack.push(0);
//        for(int i = 1; i < height.size(); ++i)
//        {
//            if(height[my_stack.top()] >= height[i])
//                my_stack.push(i);
//            else
//            {
//                while(!my_stack.empty() && height[my_stack.top()] < height[i])
//                {
//                    // 当前如果能弹出元素 —— 那么其右边界一定已知, 左边界就是当前元素在栈中的前一个元素
//                    int mid = my_stack.top();
//                    my_stack.pop();
//                    // 寻找左侧边界，同时对于这个左侧没有更大数值的元素，进行跳过
//                    if(my_stack.empty()) break;
//                    int left = my_stack.top();
//                    int min_value = height[left] > height[i] ? height[i] : height[left];
//                    res += (min_value - height[mid]) * (i-left-1);
//                    cout << res << ' ';
//                }
//                my_stack.push(i);
//            }
//        }
//    }
//
//    int trap(vector<int>& height)
//    {
//        if(height.empty()) return 0;
//        traversal(height);
//        return res;
//    }

    /* 尝试使用双指针的方法解决对应的问题 */
    // 双指针解决类似的问题 主要经过三次对height数组的遍历操作 相当于在最后一次扫描之后就可以直接跟据左右高度获取到当前雨水量
//    int trap(vector<int>& height)
//    {
//        vector<int> left(height.size(), 0);
//        vector<int> right(height.size(), 0);
//        for(int i = 0; i < left.size(); ++i)
//        {
//            if(i == 0) left[i] = height[i];
//            else
//                left[i] = max(left[i-1], height[i]);
//        }
//        for(int j = right.size()-1; j >= 0; --j)
//        {
//            if(j == right.size()-1) right[j] = height[j];
//            else
//                right[j] = max(right[j+1], height[j]);
//        }
//
//        int res = 0;
//        for(int i = 0; i < height.size(); ++i)
//        {
//            res += min(left[i], right[i]) - height[i];
//        }
//        return res;
//    }


        // note 之前的解决方法是直接使用队列以及双指针来的, 但是实际上使用栈会更简单一些 | 具体涉及到接雨水问题, 需要解决的队列碰到一个更大的元素之后, 还需要判断左侧更大的元素，这样才能形成一个凹形来接取雨水
        int trap(vector<int>& height) {
            stack<int> s;
            // 栈中存放的数据是index 存在index才能计算整个雨水的容量, 并且在实际的计算中, 需要计算的是下一个stack中的top()值到当前height[i]的一个差值
            s.push(0);
            int res = 0;

            for(int i = 1; i < height.size(); ++i)
            {
                while(!s.empty() && height[s.top()] < height[i])
                {
                    if(s.size() <= 1)
                        s.pop();
                    else
                    {
                        auto tmp = s.top();
                        s.pop();
                        // 注意这里的凹槽计算容积来处理数据
                        res += ( min(height[s.top()], height[i]) - height[tmp] ) * (i - 1 - s.top());
                    }
                }
                s.push(i);
            }
            return res;
        }
};

//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution42;
int main() {
    Solution solution = Solution();

    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << solution.trap(a);
    return 0;
}
