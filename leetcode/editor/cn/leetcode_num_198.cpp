#include "../../../stdc.h"
using namespace std;

namespace solution198{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 入门的打家 | dp[i]表示到第i家所能积累的金钱的最大值
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);

        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);

        // note 最一开始容易犯的一个错误, dp[i]的定义是取当前0~i的取值最大值,但是在dp[1]的取值上最一开始还是写成了 dp[1] = nums[1] !!!
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); ++i)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        return dp[nums.size()-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution198;
int main() {
    Solution solution = Solution();

    return 0;
}
