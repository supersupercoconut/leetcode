//import universal *.h
#include "../../../stdc.h"

using namespace std;



namespace solution518{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        // 完全背包问题，并且分析最终组合数量的多少
        vector<unsigned long long> dp(amount+1,0);
        // note 我推导这里时发现如果dp[0] = 1，其可以用于表示dp[j-coins[i]]中j == coins[i]的情况，即只是用coins[i]来填充满j容量的背包
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++i)
        {
            // 硬币值大于最大值可以直接跳过
            for(int j = coins[i]; j <= amount; ++j)
            {
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution518;
int main() {
    Solution solution = Solution();

    return 0;
}


//// note 卡码网52题，最基础的完全背包问题
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n,v;
//    cin >> n >> v;
//    vector<int> weight(n,0);
//    vector<int> value(n,0);
//
//    // 读取数据
//    for(int i = 0; i < n; i++)
//        cin >> weight[i] >> value[i];
//
//    cout << n <<' '<< v << endl;
//    for(int i = 0; i < n; ++i)
//        cout << weight[i] << ' ' << value[i] <<endl;
//
//    // 先遍历物体后遍历背包
//    vector<int> dp(v+1,0);
//    for(int i = 0; i < n; ++i)
//    {
//        for(int j = weight[i]; j <= v; ++j)
//        {
//            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
//        }
//    }
//
//    for(auto i : dp)
//        cout << i << " ";
//    cout << dp[v];
//    return 0;
//}
