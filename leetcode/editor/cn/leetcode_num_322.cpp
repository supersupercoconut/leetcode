#include "../../../stdc.h"
using namespace std;

namespace solution322{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;
        // dp[i]数组中对应的是数值达到i, 其对应的硬币数量(这里赋值为0实际上是增加了自己的难度的)
        vector<int> dp(amount+1,0);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 0; j < coins.size(); ++j)
            {
                // 保证能放下去
                if(i == coins[j]) dp[i] = 1;
                else if(i > coins[j])
                {
                    // 说明没有任何coins能累加出来这个结果
                    if(dp[i-coins[j]] == 0)
                        continue;
                    else
                    {
                        if(dp[i] == 0)
                            dp[i] = dp[i-coins[j]] + 1;
                        else
                            // note 实际上是不存在dp[i]不为0但是dp[i-coins[j]]为0的可能性的,因为dp[i]的赋值一定是依赖于dp[i-coins[j]]不为0的
                            dp[i] = min(dp[i], dp[i-coins[j]]+1);
                    }
                }

            }
        }
        if(dp[amount] == 0) return -1;
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution322;
int main() {
    Solution solution = Solution();

    return 0;
}
