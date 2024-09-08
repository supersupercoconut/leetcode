#include "../../../stdc.h"

using namespace std;


//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回 滑动窗口中的最大值 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2780 👎 0


namespace solution239{
    //leetcode submit region begin(Prohibit modification and deletion)
class myDeque{
    // 只为int类型来服务，不服务其他部分
public:
    int pop()
    {
        // 弹出
        if(outStack.empty())
        {
            while(!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int val = outStack.top();
        return val;
    }
    void push(int val)
    {
        // 压入
        inStack.push(val);
    }


private:
    stack<int> inStack;
    stack<int> outStack;

};

class Solution{
public:

    // 代码随想录中给出来的方法是单调队列(这里没有写完)
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        myDeque temp;
        stack<int> res;

        for(int i = 0; i<k; i++)
            temp.push(nums[i]);

        int k_max;
        int k_max_2; // k-1窗口中的最大值(不算第一个元素)
        for()




    }

};




//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution239;
int main() {
    Solution solution = Solution();

    return 0;
}
