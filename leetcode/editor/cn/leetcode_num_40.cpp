//import universal *.h
#include "../../../stdc.h"

using namespace std;


//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1595 👎 0


namespace solution40{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> path = {};
    vector<vector<int>> res = {};

    void backtracking(vector<int>& candidates, int target, int sum, int start_index)
    {
        if(sum >= target)
        {
            if(sum == target) res.push_back(path);
            return;
        }

        for(int i = start_index; i < candidates.size(); ++i)
        {
            // 这里i的取值一定是在candidates之中的 | 元素不能重复，所以start_index需要+1 | 但是在每一层进行选择数据时，如果前一个与后一个相同了，这就没必要再来一边，所以加入i != start_index的判断
            // note 代码随想录中说的很好: 我们要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重(我自己去重逻辑感觉要比随想录中的更加简洁)
            if(i != start_index && candidates[i-1] == candidates[i])
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i+1);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    // 同样是给定candidates, 在其中选取元素计算得到target元素
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return {};
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution40;
int main() {
    Solution solution = Solution();

    return 0;
}

