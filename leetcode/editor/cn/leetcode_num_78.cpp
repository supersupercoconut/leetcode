//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution78{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /** 本题主要是将所有中间结果都需要保留，不需要到走到n叉树的叶子节点处才返回 **/
    // 默认res中包含一个空集
    vector<vector<int>> res = {{}};
    vector<int> path = {};
    void backtracking(vector<int>& nums, int start_index)
    {
        for(int i = start_index; i<nums.size(); ++i)
        {
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // 空集也是自己的子集
        if(nums.empty()) return res;
        backtracking(nums,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution78;
int main() {
    Solution solution = Solution();

    return 0;
}

