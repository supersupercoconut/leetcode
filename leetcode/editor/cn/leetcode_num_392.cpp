#include "../../../stdc.h"
using namespace std;

namespace solution392{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        // 直接按照两个字符串对应分析，最后的最长公共子序列等于s即可
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size() + 1,0));
        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 1; j <= t.size(); ++j)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        if(dp[s.size()][t.size()] == s.size()) return true;
        else
            return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution392;
int main() {
    Solution solution = Solution();

    return 0;
}
