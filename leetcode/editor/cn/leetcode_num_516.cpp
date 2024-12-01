//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution516{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        // 因为是子序列，dp只能返回长度信息，不能跟子串一样表示是否是回文字串 | 基于之前最大公共子序列的处理方法，成功解决
        int length = 0;
        // dp[i][j]代表起始位置为i, 终止位置为j(左闭右闭)子序列的中最长回文字串长度
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));

        for(int i = s.size()-1; i >=0; --i)
        {
            for(int j = i; j < s.size() ;++j)
            {
                if(s[i] == s[j])
                {
                    if(i != j) dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = 1;// i,j相同,字符串长度只能是1
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size()-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution516;
int main() {
    Solution solution = Solution();

    return 0;
}

