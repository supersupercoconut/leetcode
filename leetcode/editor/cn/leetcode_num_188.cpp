#include "../../../stdc.h"
using namespace std;

namespace solution188{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        // note 目前属于是最普遍的版本, 一共只能进行k次操作 所以对应的第二位状态为2*k+1中状态
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1,0));
        // 在状态中 奇数表示持有 偶数表示不持有

        for(int i = 1; i < 2*k+1; i = i + 2)
            dp[0][i] = -prices[0];

        for(int i = 1 ; i < prices.size(); ++i)
        {
            // 正常操作 (这里也可以修改成为for循环中一次遍历两个)
            for(int j = 1; j < 2*k+1; ++j)
            {
                if(j % 2 == 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);
                else
                {
                    if(j == 1) dp[i][1] = max(dp[i-1][1], -prices[i]); // 不维护0状态
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);
                }
            }
        }
        // 默认完成最后一次操作的金额数会大于等于其他操作数
        return dp[prices.size()-1][2*k];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution188;
int main() {
    Solution solution = Solution();

    return 0;
}
