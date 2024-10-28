#include "../../../stdc.h"
using namespace std;

namespace solution343{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 相同类似的问题有很多，这个问题从一开始是没有思路的 | n拆分成k个数字 并且使其乘积最大 - 后面的分解结果可以依赖与之间计算出来的最大乘积(不需要重复计算，减小自由度)
    int integerBreak(int n)
    {
        /*** 1. 贪心(可以从数学上证明最好令每一个拆分数之间近似相同并且接近为3最佳) ***/
        /*** 2. 动态规划方法 ***/
        vector<int> dp = {};
        dp.resize(n+1);
        dp[2] = 1;

        // 实际对应的数字对应的就是从3开始的
        for(int i = 3; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                // 这里比较dp[i-j]*j 而不是使用dp[i-j]*dp[j] —— 前者是将i从分解三份开始处理的，但是对于后者是默认分解四份开始处理，四份分解一定可以使用三份分解来表示出来 —— 并且有很多情况下，三份分解乘积会比四份分解的值更大
                dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j)));
            }
//            cout << dp[i] << ' ';
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution343;
int main() {
    Solution solution = Solution();

    return 0;
}
