//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution90{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> res = {{}};
    vector<int> path = {};

    // 虽然包含了重复元素，但是其在实际处理上只需要保证树的每一层不需要选择重复元素即可
    void backtracking(vector<int>& nums, int start_index)
    {
        for(int i = start_index;  i < nums.size() ; ++i)
        {
            // 去重
            if(i != start_index && nums[i-1] == nums[i])
                continue;
            else
            {
                path.push_back(nums[i]);
                res.push_back(path);
                backtracking(nums,i+1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        backtracking(nums,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution90;
int main() {
    Solution solution = Solution();

    return 0;
}

