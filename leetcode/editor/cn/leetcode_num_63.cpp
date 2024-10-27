#include "../../../stdc.h"
using namespace std;

namespace solution63{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 在移动的道路上会出现障碍物
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        // 对应 m*n 的大小
        int m = obstacleGrid.size();
        int n  = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        cout << "m: " << m << " "<< "n: " << n << endl;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // note  第一遍的处理逻辑过于简单 (对于存在障碍的区域直接默认为0即可) | 判断过程比较复杂，主要是对于 i == 0与j==0的情况没有更好概括方法
                if( obstacleGrid[i][j] == 1 ) continue;
                // 单独判断 i == 0 以及 j == 0的情况
                if(i == 0 && j == 0)
                    dp[i][j] = 1; // 如果这里是障碍自然为0了
                else if(i == 0)
                    dp[i][j] = dp[i][j-1];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution63;
int main() {
    Solution solution = Solution();

    return 0;
}
