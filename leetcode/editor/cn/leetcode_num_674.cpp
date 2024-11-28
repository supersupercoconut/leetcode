#include "../../../stdc.h"

using namespace std;
namespace solution674{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int res = 1; // 如果nums不为空, 最后对应的res至少为1
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
            else
                dp[i] = 1;

            res = res > dp[i] ? res : dp[i];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution674;
int main() {
    Solution solution = Solution();

    return 0;
}
