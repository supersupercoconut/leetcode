#include "../../../stdc.h"

using namespace std;

namespace solution70{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /***
     * 本问题属于是经典的动态规划题目 主要需要: 1. 确定DP数组以及初始化  2.递推方程
     * (1) dp数组在这里代表到这个部分时的方法
     * (2) 递推方法与 59 斐波那契数 相同
     * ***/

    int climbStairs(int n)
    {
        if(n <= 1) return n;
        int dp[2];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution70;
int main() {
    Solution solution = Solution();

    return 0;
}
