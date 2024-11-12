#include "../../../stdc.h"
using namespace std;
namespace solution494{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 回溯方法会超时，这里转而使用动态规划方法 1.dp数组含义 2.dp数组初始化 3.递推过程
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum  = 0;
        for(auto i : nums)
            sum += i;

        // 整个部分可以转换成为背包问题, bagSize对应的是正数的取值情况
        if(( sum + target ) % 2 != 0) return 0;
        int bagSize = (sum+target)/2;
        if(bagSize < 0) return 0;
        /*** dp为二维数组 ***/
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize+1, 0));

        // note 这里的bagSize本身代表的是元素的取值, 所以对于元素取值为0的情况
        // 单独处理第一行元素以及第一列元素
        if(nums[0] <= bagSize) dp[0][nums[0]] = 1;

        int zeroNumber = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0) zeroNumber++;
            // 就相当于n个元素的全排列 任意取一个可以，任意取两个可以等等，计算公式就是2^n
            dp[i][0] = (int)pow(2.0, zeroNumber);
        }

        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 1; j <= bagSize; ++j)
            {
                if(nums[i] > j) dp[i][j] = dp[i-1][j];
                else
                {
                    // 正常的递推方法(但是i-1因为这种是01背包问题)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                }
            }
        }

        for(auto i : dp)
        {
            for(auto j : i)
                cout << j << ' ';
            cout << endl;
        }

        // 最后只需要考虑最后满足bagSize的方法
        return dp[nums.size()-1][bagSize];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution494;
int main() {
    Solution solution = Solution();

    return 0;
}
