#include "../../../stdc.h"
using namespace std;

namespace solution139{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 这个问题在分析回文字串，之前实现过使用回溯方法实现该问题，目前的实现逻辑是直接使用完全背包解决问题
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size()+1,0);
        // 对于单词出现的顺序没有要求，所以需要分析的是排列问题
        dp[0] = 1;
        for(int i = 1;  i <= s.size(); ++i)
        {
            for(int j = 0; j < wordDict.size(); ++j)
            {
                if(i >= wordDict[j].size())
                {
                    // 需要保证从wordDict[j]到i的这一段序列中的字符串都属于wordDict中的数据
                    auto temp = s.substr(i - wordDict[j].size(), wordDict[j].size());
                    if(temp == wordDict[j] && dp[i - wordDict[j].size()] == 1)
                        dp[i] = 1;
//                    else
//                    {
//                        // 这里赋值的dp不能覆盖之前赋值的dp(不过既然默认都是0,这里可以不进行dp的赋值)
//                        if(dp[i] != 1)
//                            dp[i] = 0;
//                    }
                }
//                for(auto a : dp)
//                    cout << a << ' ';
//                cout << endl;
            }
        }
        return dp[s.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution139;
int main() {
    Solution solution = Solution();

    return 0;
}
