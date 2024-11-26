#include "../../../stdc.h"
using namespace std;

namespace solution123{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // note 相比与121与122 这里引入了对于交易值的限制(最多只能交易两次)
        /*** 借助随想录中的方法实现问题(有的实现逻辑是使用一个三维数组来表示状态，这里不如使用二维数据来处理简单) ***/
        vector<vector<int>> dp(prices.size(), vector<int>(5,0));
        // 初始化第一行中的数据均要完成初始化
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            // dp[i][0] 属于一直到第i天都没有开始操作，那么如果从这里开始买入的话，必然是-prices[i]
            dp[i][1] = max(dp[i-1][1], -prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        return dp[prices.size()-1][4];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution123;
int main() {
    Solution solution = Solution();

    return 0;
}
