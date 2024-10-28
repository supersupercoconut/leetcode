#include "../../../stdc.h"
using namespace std;
namespace solution96{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 实现二叉搜索树(左 < 中 < 右) | dp数组中需要保存对每一个n值计算出来的最大二叉搜索树（因为不是平衡二叉搜索树，其可以直接使用）
    // note 解决本问题最简单的思路就是理解到 dp[i]数组对应的是当前子树中有i个点对应而不是中间节点取值为i时对应的情况
    int numTrees(int n)
    {
        vector<int> dp(n+1);    // 给定创建 大小，并且默认元素都为0
        dp[0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            // j 代表左子树中的节点数量(中间节点也需要1，所以是i-1)
            for(int j = 1; j <= i; ++j)
                dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution96;
int main() {
    Solution solution = Solution();

    return 0;
}
