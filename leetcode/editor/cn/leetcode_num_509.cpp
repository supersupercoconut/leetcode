#include "../../../stdc.h"
using namespace std;
namespace solution509{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 相当于计算F(n)的数值
    int fib(int n)
    {
        /*** 简单方法(直接使用迭代可以实现出来) ***/
//        if(n == 0 ) return 0;
//        if(n == 1) return 1;
//        int last_value = 1;
//        int last_last_value = 0;
//        int now = 0;
//        for(int i = 2; i <= n; ++i)
//        {
//            now = last_value + last_last_value;
//            last_last_value = last_value;
//            last_value = now;
//        }
//        return now;

        /*** 动态规划方法 ***/
        // 题目中已经给定了dp数组的初始化方法(dp[0] = 0 dp[1] = 1), 并且给定了递推公式
        if(n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            int temp = dp[0];
            dp[0] = dp[1];
            dp[1] = dp[1] + temp;
        }
        return dp[1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution509;
int main() {
    Solution solution = Solution();
    return 0;
}
