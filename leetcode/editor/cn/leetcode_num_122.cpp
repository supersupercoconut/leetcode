#include "../../../stdc.h"

using namespace std;

namespace solution122{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // 首先整个流程中是将整数数组直接输入，相当于是在已知整个股票价格的基础上进行操作 | 在这种设置基础上我觉得使用正利润来进行整体的计算相当合理
        if(prices.empty()) return 0;
        int res = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] <= prices[i-1]) continue;
            else
                res = res + prices[i] - prices[i-1];
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution122;
int main() {
    Solution solution = Solution();

    return 0;
}
