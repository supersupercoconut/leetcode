//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution491{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> res = {};
    vector<int> path ={};
    /*** 1.个人方法(与随想录中的方法类似), 之前忽略的一点是 —— 由于这里不能将原始数组进行排序，这就导致了之前的去重方法不能再次使用，现在使用的去重方法只能对每一层设置一个数组或者哈希表来处理
     *  PS: {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1} 之前就是再这个数组上出了错
     *
     *
     * ***/
    void backtracking(vector<int>& nums, int start_index)
    {
        unordered_set<int> used = {};
        for(int i = start_index; i<nums.size() ;++i)
        {
            // 这里没有想到可以写的这么简洁，只需要path中的前一个永远小于新来的数就可以了 | 而且只需要这个nums[i]数据没有进入path, 那么路径中其余与nums[i]相同的元素也不需要放进来
            if((path.size() != 0 && path.back() > nums[i]) || used.find(nums[i]) != used.end()) continue;
            else
            {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                if(path.size() >= 2) res.push_back(path);
                backtracking(nums, i+1);
                path.pop_back();
            }
        }



        // 对每一层新建一个 unordered_set 来表示used情况
//        unordered_set<int> used = {};
//        for(int i = start_index; i < nums.size(); ++i)
//        {
//            // 数组中包含重复元素(需要在同一层去重)
//            if(used.find(nums[i]) != used.end()) continue;
//            else
//            {
//                used.insert(nums[i]);
//                path.push_back(nums[i]);
//                // 升序判断
//                if(path.size() >=2)
//                {
//                    int j = 1;
//                    for(; j < path.size(); ++j)
//                    {
//                        if(path[j] >= path[j-1]) continue;
//                        else break;
//                    }
//                    if(j == path.size()) res.push_back(path);
//                    else
//                    {
//                        // 剩余部分不需要再遍历
//                        path.pop_back();
//                        return;
//                    }
//                }
//
//                backtracking(nums, i+1);
//                path.pop_back();
//            }
//        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.empty()) return res;
        backtracking(nums,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution491;
int main() {
    Solution solution = Solution();
    vector<int> a = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    for(auto i : solution.findSubsequences(a))
    {
        for(auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}

