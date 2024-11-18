//import universal *.h
#include "../../../stdc.h"
using namespace std;


namespace solution377{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 同样为完全背包问题，因为这里不需要处理将所有的组合情况全部排列出来，故可以不使用回溯，利用动态规划中的dp数组继承之前的组合数
    int combinationSum4(vector<int>& nums, int target)
    {
        // note 这里与之前完全背包问题的区别在于其需要考虑的是一个排列，顺序对最后的结果也是有影响的 | 通过更改for的遍历顺序, 可以非常方便的解决排序问题
        vector<unsigned long long> dp(target+1,0);
        dp[0] = 1;
        for(int i = 0; i <= target; ++i)
        {
            for(int j = 0; j < nums.size() ; ++j)
            {
                if(i >= nums[j])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution377;
int main() {
    Solution solution = Solution();

    return 0;
}

