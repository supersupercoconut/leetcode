#include "../../../stdc.h"
using namespace std;

namespace solution121{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 这里不太理解为什么要进行这部分的转换(给我的感觉是买入只有一次，所以这里只考虑第一次买入后当前手中的现金数量)
    // 这部分对应的dp数组中包含了两种状态 —— 持有以及不持有这个股票所对应的状态(二维dp数组)
    int maxProfit(vector<int>& prices)
    {
        // 多一维包含了第0天的情况
        vector<vector<int>> dp(prices.size(), vector<int>(2,0) );
        // 第二维中的 0代表持有 1代表不持有(说明可能是在当天卖出) dp本身代表了当前现金数量
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        // i代表天数
        for(int i = 1; i < prices.size(); ++i)
        {
            // note 这里感觉随想录中没有解释清楚怎么体现出来只买卖一次的情况的
                // 1. 买入: 因为之前属于是没有持有股票的状态，所以买入之后的现金数直接变成当前的花销 -prices[i]
                // 2. 卖出: 需要考虑到之前买入的时候的亏钱，所以需要加上dp[i-1][0]来进行考虑
            // dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[prices.size()-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution121;
int main() {
    Solution solution = Solution();

    return 0;
}
