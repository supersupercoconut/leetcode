//import universal *.h
#include "../../../stdc.h"

using namespace std;
namespace solution647{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 一开始没有想到一个回文字串的判断中也是直接使用了二维dp数组进行处理 这里i代表起始位置, j代表中止位置
    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        // 因为dp[i][j]需要依赖于dp[i+1][j-1]是从左下角递推，所以这里需要先从后面的行数开始遍历
        int res = 0;
        for(int i = s.size()-1; i >= 0; --i)
        {
            for(int j = i; j < s.size(); ++j)
            {
                // 首尾相同
                if(s[i] == s[j])
                {
                    if(i + 1 <= j - 1) dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = 1;

                    if(dp[i][j])
                        res++;
                }
            }
        }

//        for(auto i : dp)
//        {
//            for(auto j : i)
//                cout  << j << ' ';
//            cout << endl;
//        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution647;
int main() {
    Solution solution = Solution();

    return 0;
}

