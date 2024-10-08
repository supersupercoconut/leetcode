#include "../../../stdc.h"

using namespace std;
namespace solution77{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 使用回溯处理(回溯等效成为二叉树,输入参数中加入path,记录当前路径) | 处理组合逻辑并不能在时间复杂度上获取到提升，只是在使用逻辑上获取到优化(只可能在一些处理中加入剪枝操作)
    vector<vector<int>> res = {};
    vector<int> path = {};
    void backtracking(int n, int k, int start_index)
    {
        // 判断终止条件
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }
        // 从start_index开始，遍历到n
        for(int i = start_index; i <= n; ++i)
        {
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();    // 增加这里部分的主要作用就是满足下一次循环开始的时候, path去除上一次的影响
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution77;
int main() {
    Solution solution = Solution();
    solution.combine(4, 2);

    return 0;
}
