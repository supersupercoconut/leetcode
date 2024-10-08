//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution39{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> path = {};
    vector<vector<int>> res = {};

    // sum 用于保留结果
    void backtracking(vector<int>& array, int sum, int start_index, const int target)
    {
        if(sum > target )
            return;

        else if(sum == target)
        {
            res.push_back(path);
            return;
        }

        // note 这里对于start_index的设置其实很简单, 但是一开始的时候没有想起来，这里所有的改变就是让每一层的元素都可以选择当前元素 | 但是同一层的其他部分进行操作的时候，还是不能选择之前的元素！！！
        for(int i = start_index; i < array.size() ;i++)
        {
            sum += array[i];
            path.push_back(array[i]);
            backtracking(array, sum, i, target);
            path.pop_back();
            sum -= array[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return {};
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0, target);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution39;
int main() {
    Solution solution = Solution();
    return 0;
}

