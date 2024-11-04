//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution416{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 数组问题转换成为了背包问题，并且这里选择target是非常有技巧的 | 相当于是在设定容量的情况下去选择，不会有超过容量的情况(选择的物体总量最多就到这里)
    bool canPartition(vector<int>& nums)
    {
//        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;

        if(sum % 2 != 0) return false;
        int target = sum / 2;
        cout << target << endl;
        vector<int> dp(target+1, 0);
        // i 代表当前可以考虑的元素值，j代表当前最大容量
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = target; j >= nums[i] ; --j)
            {
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
        }

        for(auto i : dp)
            cout << i << ' ';

        if( dp[target] == target ) return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution416;
int main() {
    Solution solution = Solution();

    return 0;
}











/* 补充leetcode中没有包含的最简单的0-1背包基础问题 卡码网46(问题并不复杂，主要是处理过程)
 * dp[][]二维的数组，其可以包含了所有在当前背包剩余多少容量的情况下，其携带货物的最大价值 - 整体的最大价值就是最后的 dp[m-1][n] (注意下dp的列数为n+1)
 * dp[][]不断地进行复用
 * */

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int m = 0, n = 0;
//    cin >> m >> n;
//
//    // 整理种类以及价值
//    vector<int> weight(m,0);
//    vector<int> value(m,0);
//    for(int i = 0; i < m; ++i)
//        cin >> weight[i];
//
//    for(int i = 0; i < m; ++i)
//        cin >> value[i];
//
//    // 定义二维数组(n要加1)
//    vector<vector<int>> dp(m, vector<int>(n+1, 0));
//    int res = 0;
//    for(int i = 0; i < m; ++i)
//    {
//        for(int j = 0; j <= n; ++j)
//        {
//            if(j == 0) dp[i][j] = 0;
//            else if(j - weight[i] < 0)
//            {
//                if(i == 0) dp[i][j] = 0;
//                else
//                    dp[i][j] = dp[i-1][j]; // 放不下当前元素
//            }
//
//            else
//            {
//                // 这里确定可以放下去
//                if(i == 0)
//                    dp[i][j] = value[i];
//                else
//                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
//            }
//            res = res > dp[i][j] ? res : dp[i][j] ;
//        }
//    }
//
////    for(int i = 0; i < m; ++i)
////    {
////        for(int j = 0; j <= n; ++j)
////            cout << dp[i][j];
////        cout << endl;
////    }
//
//
//    cout << res;
//    return 0;
//
//}

//// 依赖滚动一维数组处理问题（虽然使用的是滚动数组，但是其仍然是需要两层for循环的遍历阶段）
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    // m物体种类 n背包容量
//    int m = 0, n = 0;
//    cin >> m >> n;
//
//    // 整理种类以及价值
//    vector<int> weight(m,0);
//    vector<int> value(m,0);
//    for(int i = 0; i < m; ++i)
//        cin >> weight[i];
//
//    for(int i = 0; i < m; ++i)
//        cin >> value[i];
//
//    // 定义一维数组(使用层for循环解决问题，初始化直接全部为0)
//    vector<int> dp(n+1,0);
//
//    for(int i = 0; i < m; ++i)
//    {
//        for(int j = n; j >=0  ;--j)
//        {
//            if( j - weight[i] >= 0 )
//            {
//                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
//            }
//        }
//    }
//    // 返回最后一个默认最大
//    cout << dp[n];
//    return 0;
//}