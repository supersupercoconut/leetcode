#include "../../../stdc.h"
using namespace std;

namespace solution1035{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 相当于求解最大相同子序列长度(与之前的实现逻辑是一样的， 其相互之间连线并不会出现交叉)
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        // dp[i][j]的定义相当于是分析从0~i-1以及0~j-1中的共同序列长度(这里采用的是随想录中的写法，之前自己的写法在初始化的时候比较复杂一些)
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));

        for(int i = 1; i <= nums1.size(); ++i)
        {
            for(int j = 1; j <= nums2.size(); ++j)
            {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1035;
int main() {
    Solution solution = Solution();

    return 0;
}
