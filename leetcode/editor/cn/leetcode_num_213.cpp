#include "../../../stdc.h"

using namespace std;

namespace solution213{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 首尾连接可以直接分析前三个数据,就可以判断是否使用第一个元素
    int rob(vector<int>& nums)
    {
        // 该问题在一开始的想法非常复杂，想设置一个flag元素值取分析是否需要选第一个元素，但是这个flag需要对于每一次进行循环的时候都要进行处理，倒不如随想录中的方法来的简单 —— 直接比较使用首元素与不使用首元素两种情况来分析
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // 情况二
        int result2 = robRange(nums, 1, nums.size() - 1); // 情况三
        return max(result1, result2);
    }

    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution213;
int main() {
    Solution solution = Solution();

    return 0;
}
