#include "../../../stdc.h"
using namespace std;

namespace solution746{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // cost[i] 对应的部分是从i向上爬需要的耗费资源，并且所需要爬上去的台阶数是与cost的size()是一样的
    // dp[] 数组代表的到达这里耗费的资源，在第i位置的耗费资源为dp[i-1]与dp[i-2]比较结果
    int minCostClimbingStairs(vector<int>& cost)
    {
        // 最小出现的可能性
        if(cost.size() == 2)
            return cost[0] > cost[1] ? cost[1] : cost[0];

        int dp[2];
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= cost.size(); ++i)
        {
            int temp = ( dp[0] + cost[i-2] ) > ( dp[1] + cost[i-1] ) ? ( dp[1] + cost[i-1] ) : ( dp[0] + cost[i-2] );
            dp[0] = dp[1];
            dp[1] = temp;
            // 最后返回的部分说明: temp才应该是最后应该返回的部分(即cost.size对应的台阶，dp[0]对应的是cost最后一个元素处对应的体力，其到现在还没有出去)
            cout << "dp[0]: " << dp[0] << " " << "dp[1]: " << dp[1] << endl;
        }

        return dp[1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution746;
int main() {
    Solution solution = Solution();

    return 0;
}
