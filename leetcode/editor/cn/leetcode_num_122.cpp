#include "../../../stdc.h"

using namespace std;

namespace solution122{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        /*** 贪心方法 ***/
        // 首先整个流程中是将整数数组直接输入，相当于是在已知整个股票价格的基础上进行操作 | 在这种设置基础上我觉得使用正利润来进行整体的计算相当合理
//        if(prices.empty()) return 0;
//        int res = 0;
//        for(int i = 1; i < prices.size(); ++i)
//        {
//            if(prices[i] <= prices[i-1]) continue;
//            else
//                res = res + prices[i] - prices[i-1];
//        }
//        return res;

        /*** 动规方法 ***/
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            // 0表示持有股票(与121在这里不同，即说明交易可以进行多次)
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            // 1表示未持有股票
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        // 输出未持有股票的，说明当前一定将所有的股票转换成为了现金
        return dp[prices.size()-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution122;
int main() {
    Solution solution = Solution();

    return 0;
}
