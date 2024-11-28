#include "../../../stdc.h"
using namespace std;
namespace solution718{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 分析元素取值, 一开始没有想明白dp数组可以定义成为二维的，并且使用两个for循环就可以分析完毕
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int res = 0;
        // dp[i][j] 定义成为 A以i结尾 B以j结尾 的最长子序列的长度值 | 但是实际中应该输出的dp[][]数组未必是最长的子序列(因为最长的未必会以i,j结尾)
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(),0));
        for(int i = 0; i < nums1.size(); ++i)
        {
            if(nums1[i] == nums2[0]) dp[i][0] = 1;
            res = res > dp[i][0] ? res : dp[i][0];
        }

        for(int i = 0; i < nums2.size(); ++i)
        {
            if(nums1[0] == nums2[i]) dp[0][i] = 1;
            res = res > dp[0][i] ? res : dp[0][i];
        }

        for(int i = 1; i < nums1.size(); ++i)
        {
            for(int j = 1; j < nums2.size(); ++j)
            {
                if(nums1[i] == nums2[j]) dp[i][j] = dp[i-1][j-1] + 1;
                res = res > dp[i][j] ? res : dp[i][j];
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution718;
int main() {
    Solution solution = Solution();

    return 0;
}
