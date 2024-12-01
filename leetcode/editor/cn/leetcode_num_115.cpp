#include "../../../stdc.h"

using namespace std;
namespace solution115{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t)
    {
        // note 这里并不是使用一种显式的手段去对s字符串的每一种情况都进行分析, 可以手动列出来dp[][]数组的取值分析 | 最后dp的取值大于int表示的范围，所以修改成为unsigned
        vector<vector<unsigned>> dp(t.size(), vector<unsigned>(s.size(),0));
        // 初始化只需要初始化第一行(保证s的子序列要长度t的子序列)
        if(t[0] == s[0]) dp[0][0] = 1;

        int temp = dp[0][0];
        for(int i = 1; i < s.size(); ++i)
        {
            if(t[0] == s[i])
                dp[0][i] = ++temp;
            else
                dp[0][i] = dp[0][i-1];
        }


        for(int i = 1; i < t.size(); ++i)
        {
            for(int j = 1; j < s.size(); ++j)
            {
                if(t[i] == s[j]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t.size()-1][s.size()-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution115;
int main() {
    Solution solution = Solution();

    return 0;
}
