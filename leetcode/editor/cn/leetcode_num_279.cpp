#include "../../../stdc.h"
using namespace std;

namespace solution279{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSquares(int n)
    {
        // dp[i]表示和为i的完全平方数的最小数量
        vector<int> dp(n+1, INT_MAX);
        // 由于n的取值为10^4,所以其对应的完全平方数的数量不会超过100
        dp[0] = 0;
        for(int i = 1; i <= 100; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                if(j >= i*i)
                {
                    // 这里不会出现dp[j-i*i]为INT_MAX又被加一导致越界的原因是存在一个完全平方数为1,其会保证后续的所有j的取值都至少为1
                    dp[j] = min(dp[j], dp[j-i*i]+1);
                }
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution279;
int main() {
    Solution solution = Solution();

    return 0;
}
