//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution15{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /* 使用hash方法没有解决该问题 */
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        // int, vector<int> 前面数值 后面下标(可能出现相同元素下标)
//        unordered_map<int, vector<int> > search;
//        for(int i = 0; i < nums.size(); i++)
//        {
//          if(search.find(nums[i]) == search.end()){
//            search[nums[i]] = vector<int>{i};
//          }
//          else
//            search[nums[i]].push_back(i);
//        }
//
//        // 这里只能实现有关于不同下标的组合逻辑
//        vector<vector<int> > res = {};
//        for(int i = 0; i < nums.size(); ++i)
//        {
//            for(int j = i + 1; j < nums.size(); ++j)
//            {
//                int tmp = - nums[i] - nums[j];
//                if(search.find(tmp) != search.end())
//                {
//                    // note 这里不仅要求下标不同，还限制了数据不能相同 所以这样方法不能使用(这里最复杂的部分在于没有办法进行去重)
//                    for(auto k : search[tmp])
//                        if(k != i && k != j) res.push_back({nums[i], nums[j], nums[k]});
//                }
//            }
//        }
//        return res;
//    }
    /* 随想录中给定的方法是直接使用双指针解决 */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // 首先进行排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0) return res;
            // 除去第一次i可以直接使用, 下一次的i需要去重
//            if(i > 0 && nums[i] == nums[i-1]) continue;
            // note 之前这里用的是++i而不是continue 问题在于去重不够
            while(i > 0 && nums[i] == nums[i-1])
            {
                ++i;
                if(i > nums.size() - 1) return res;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] > 0 ) --right;
                else if(nums[i] + nums[left] + nums[right] < 0 ) ++left;
                else
                {
                    // 确定等于0那么即进行去重
                    while(left < right && nums[left] == nums[left + 1]) ++left;
                    while(left < right && nums[right] == nums[right - 1]) --right;
                    // 去重之后一定要同时收缩
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution15;
int main() {
    Solution solution = Solution();

    return 0;
}

