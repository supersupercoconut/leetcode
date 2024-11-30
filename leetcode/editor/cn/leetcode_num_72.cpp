#include "../../../stdc.h"

using namespace std;
namespace solution72{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 这种情况下的分析比较复杂(编辑距离属于是dp数组的经典问题)
    int minDistance(string word1, string word2)
    {
        // dp数组 以i-1结尾的word1以及j-1结尾的word2最小操作次数
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        for(int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for(int i = 0; i <= word2.size(); ++i)
            dp[0][i] = i;

        for(int i = 1; i <= word1.size(); ++i)
        {
            for(int j = 1; j <= word2.size(); ++j)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }

        for(auto i : dp)
        {
            for(auto j : i)
                cout << j << ' ';
            cout << endl;
        }

        return dp[word1.size()][word2.size()];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution72;
int main() {
    Solution solution = Solution();

    return 0;
}
