#include "../../../stdc.h"

using namespace std;
namespace solution1143{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 最长公共子序列(即可以删除字符串中的一些元素来比对)
    int longestCommonSubsequence(string text1, string text2)
    {
        // 以从(0,i)的text1以及(0,j)的text2两个序列中的最长子序列
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        /*** 随想录中方法 ***/
        // note 递推公式还是得分析一下dp[][]具体的推导流程才能确定下来
        for(int i = 0; i < text2.size(); ++i)
        {
            if(text2[i] == text1[0])
                dp[0][i] = 1;
            if(i != 0)
                dp[0][i] = max(dp[0][i],dp[0][i-1]);
        }
        for(int i = 0; i < text1.size(); ++i)
        {
            if(text2[0] == text1[i])
                dp[i][0] = 1;
            if(i != 0)
                dp[i][0] = max(dp[i][0],dp[i-1][0]);
        }

        // 剩余规律是列出来二维数组分析得到的
        for(int i = 1; i < text1.size(); ++i)
        {
            for(int j = 1; j < text2.size(); ++j)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

//        for(int i = 0; i < text1.size(); ++i)
//        {
//            for(int j = 0; j < text2.size(); ++j)
//            {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }


        return dp[text1.size()-1][text2.size()-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1143;
int main() {
    Solution solution = Solution();

    return 0;
}
