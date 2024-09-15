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
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2879 👎 0


namespace solution239
{
    //leetcode submit region begin(Prohibit modification and deletion)
/*** 自定义维护一个队列,完成整个功能 —— 即按照自己需求, 使得队列中的数据符合自己需求 ***/
    // 这里在实际使用中碰到的一个问题就是在push的时候，使用最前面的数据与新进入的数据进行比较，这样或导致新放入的数据如果不是最大的，这些数据就会被保存在队列中,一旦这个最大的元素被删除了，整个队列就不再是单调队列了
    class myDeque
    {
        public:
            // 如果队列元素对应该被滑动弹出的元素 - 则弹出 | 最大元素被弹出之后，剩余部分也要修正
            void pop(int val)
            {
                if(m_deque.empty() || m_deque.front() != val)
                    return;
                else
                    m_deque.pop_front();
            }

            // 新元素进入之后，需要判断前面的元素是不是小于这个元素
            void push(int val)
            {
                while(!m_deque.empty() && m_deque.back() <val)
                {
                    m_deque.pop_back();
                }
                m_deque.push_back(val);
            }

            int get_front()
            {
                return m_deque.front();
            }

        private:
            deque<int> m_deque = {};

    };

    class Solution
    {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            if(nums.empty() || nums.size() < k)
                return {};
            myDeque mydeque;
            vector<int> result = {};
            // 初始化第一个滑动窗口
            for(int i = 0; i<k; i++)
                mydeque.push(nums[i]);

            result.push_back(mydeque.get_front());

            for(int i = k; i<nums.size(); i++)
            {
                mydeque.pop(nums[i-k]);
                mydeque.push(nums[i]);
                result.push_back(mydeque.get_front());
            }
            return result;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution239;
int main() {
    Solution solution = Solution();

    return 0;
}





