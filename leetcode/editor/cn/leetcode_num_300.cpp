#include "../../../stdc.h"
using namespace std;
namespace solution300{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 寻找最长连续递增子序列(开始进入子序列问题的分析中)
    int lengthOfLIS(vector<int>& nums)
    {
        int res = 1;
        // dp[i]代表从0到i开始所有以nums[i]为结尾的最长子序列的长度
        vector<int> dp(nums.size(),1);
//        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = res > dp[i] ? res : dp[i];
        }
//        for(int i = 0; i < dp.size(); ++i)
//        {
//            cout << dp[i] << ' ';
//        }
        // 发现最大值并不一定是在最后出现的，所以重新定义一个res值
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution300;
int main() {
    Solution solution = Solution();

    return 0;
}
