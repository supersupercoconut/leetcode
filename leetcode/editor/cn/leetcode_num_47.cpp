//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution47{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 这里需要同层之间也进行去重 | 在46(nums中没有重复元素的情况中), used数组可以表示整条路线上有什么数据被使用
    vector<vector<int>> res = {};
    vector<int> used = {};
    vector<int> path = {};

    /** 这里的解决思路就是设置两个used,用于分析同层的相同性以及同一树枝上的取值 **/
    void backtracking(vector<int>& nums)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        unordered_set<int> level_use = {};
        for(int i = 0; i < nums.size(); ++i)
        {
            // used 判断当前位置其是否已经被使用
            if( used[i] == 0 )
            {
                used[i] = 1;
                // 判断同一层中是否有相同元素
                if(level_use.find(nums[i]) == level_use.end())
                {
                    path.push_back(nums[i]);
                    level_use.insert(nums[i]);
                    backtracking(nums);
                    path.pop_back();
                }
                used[i] = 0;
            }
        }

    }


    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        if(nums.empty()) return {};
        used.resize(nums.size());
        used.assign(used.size(),0);  // 全部分配为0
        backtracking(nums);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution47;
int main() {
    Solution solution = Solution();
    vector<int> nums = {1,1,3};
    solution.permuteUnique(nums);

    for(auto i : solution.res)
    {
        for(auto j : i)
            cout << j <<' ';
        cout << endl;
    }

    return 0;
}

