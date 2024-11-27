#include "../../../stdc.h"
using namespace std;
namespace solution714{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 一次买入 + 卖出成为一次交易
    int maxProfit(vector<int>& prices, int fee)
    {
        // dp状态用0表示当前持有股票 1表示当前未持有股票, 并且交易次数是无限次
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution714;
int main() {
    Solution solution = Solution();

    return 0;
}
