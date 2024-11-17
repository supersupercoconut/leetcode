#include "../../../stdc.h"
using namespace std;

namespace solution474{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 寻找最大的子集, 并且最多包含m个0 n个1 —— 相当于这个背包中包含两种重量（即从0的数量以及从1的数量来衡量这个背包是否装满）
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        // 二维dp[][]数组，分别对应0的数量与1的数量
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // note 为什么需要先遍历物体再遍历背包, 并且背包倒序遍历(这里本质上还是一维背包问题，倒序本质上是方便第一次遍历数据的时候不会重复地加入之前的元素)
        for(int i = 0; i < strs.size(); ++i)
        {
            int zeroNum = 0;
            int oneNum = 0;
            // 分析对应的01值
            for(auto temp : strs[i])
            {
                if(temp == '0') zeroNum++;
                else
                    oneNum++;
            }

            // 分析背包值
            for(int j = m; j >= zeroNum; --j)
            {
                for(int k = n; k>=oneNum; --k)
                {
                    // 设置j,k下限，防止出现数组越界问题 | 倒序能处理的情况就是第一次开始遍历的时候其对应的取值,其他遍历情况就是靠后面的取值公式计算
                    dp[j][k] = max(dp[j-zeroNum][k-oneNum]+1, dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution474;
int main() {
    Solution solution = Solution();

    return 0;
}
