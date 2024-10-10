//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution46{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> res = {};
    vector<int> path = {};
    /** 一开始是想使用unordered_map来进行处理的, 但是从unordered_map中给元素赋值以及插入什么的都想同时实现, 这种逻辑很复杂, 所以简化逻辑, 怎么简单怎么来 **/
    //   unordered_map<int,int> used = {}; // 用于判断这个数据是不是被使用 1. find()表示其是否存在, 2. value值是否为1对应其能不能使用
    vector<int> used = {};
    void backtracking(vector<int>& nums)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i] == 1) continue;
            else
            {
                path.push_back(nums[i]);
                used[i] = 1;
                backtracking(nums);
                used[i] = 0;
                path.pop_back();
            }

        }
    }

    // 不含重复数字, 利用数组中的所有没有被使用的部分进行分析
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {};
        used.resize(nums.size());
        used.assign(used.size(),0);         // 全部赋值为0
        backtracking(nums);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution46;
int main() {
    Solution solution = Solution();

    return 0;
}

