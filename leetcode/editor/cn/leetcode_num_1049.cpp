//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution1049{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 转换成为一半背包容量拿去问题很方便
    // 最后剩余的部分要求最小，说明其无论是什么样的选择方式，只去需寻找最后最小的部分
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for(auto i : stones)
            sum += i;

        int target = sum / 2;
        vector<int> dp(target+1,0);

        for(int i = 0; i < stones.size(); ++i)
        {
            for(int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2*dp[target];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1049;
int main() {
    Solution solution = Solution();

    return 0;
}

