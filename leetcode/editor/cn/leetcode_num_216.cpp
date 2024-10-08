//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution216{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> path = {};
    vector<vector<int>> res = {};
    void backtracking(int k, int n, int start_index)
    {
        // 对于题目的理解存在问题 —— k个数组合, 这些树都是1~9中的数字，然后依靠这些数据累计出来等于n
        int temp = 0;
        for(auto j : path)
            temp += j;
        // 每一次都需要重新计算
        if(temp == n)
        {
            if(path.size() == k)
                res.push_back(path);
            return;
        }
        // 剪枝(只能做一些修饰的操作, 不能特别有效的减少时间复杂度)
        else if((n-temp) < start_index)
            return;

        for(int i = start_index; i <= 9; i++)
        {
            path.push_back(i);
            backtracking(k,n,i+1);
            path.pop_back();
        }

    }


    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k,n,1);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution216;
int main() {
    Solution solution = Solution();
    solution.combinationSum3(3,7);

    return 0;
}

