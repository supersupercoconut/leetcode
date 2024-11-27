#include "../../../stdc.h"
using namespace std;
namespace solution309{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 处理相关冷冻期(比较复杂, 尤其是定义的dp数组比较复杂) | 这里也没有限制买卖次数,同样属于无限次的买卖问题
    int maxProfit(vector<int>& prices)
    {
        /***
         *  dp数组的状态分为四种:
         *    0. 持有股票: 可能是之前就持有，也可能是从冷冻期之后买入/从未持有股票状态买入
         *    1. 未持有股票: 即不是冷冻期也不是今日才卖出的股票 即保持卖出股票的状态
         *    2. 未持有股票: 今日卖出股票
         *    3. 冷冻期状态: 从卖出股票状态转换而来
         *      之前的问题中，基本上都是维持了两种状态，即持有以及不持有状态，但是这里加入一种冷冻期状态之后，就需要将状态描述的更加细致
         * ***/

        vector<vector<int>> dp(prices.size(), vector<int>(4,0));

        // 初始化 | dp[i-1][1]的初始化状态应该从下面的递推公式分析得到
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] - prices[i], dp[i-1][3] - prices[i]));
            // 保持卖出股票的状态 - 可能是之前就度过冷冻期,所以是从i-1保持卖出股票的状态实现的 或者是前一天是就是冷冻期
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i]; // 今日卖出股票，那么前一天必然是持有股票的状态
            dp[i][3] = dp[i-1][2];
        }

//        for(auto i : dp)
//        {
//            for(auto j : i)
//                cout << j << " ";
//            cout << endl;
//        }
        // 2 3 4都属于未持有股票的状态，所以都可能是最大值
        return max(dp[prices.size()-1][3] ,max(dp[prices.size()-1][1], dp[prices.size()-1][2]));

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution309;
int main() {
    Solution solution = Solution();

    return 0;
}
