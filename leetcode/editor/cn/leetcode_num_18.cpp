//import universal *.h
#include "../../../stdc.h"

using namespace std;


//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 
//
// 
// 0 <= a, b, c, d < n 
// a、b、c 和 d 互不相同 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// 你可以按 任意顺序 返回答案 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 双指针 排序 👍 2017 👎 0


namespace solution18{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        // note 思路与 15三树之和 非常相似
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > target && target >= 0) return res;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(j - i > 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    // note 最大的问题是数值直接相加可能导致的越界
                    long long int temp = nums[i] + nums[j];
                    temp = temp + nums[left] + nums[right];
                    if(temp < target) ++left;
                    else if(temp > target) --right;
                    else
                    {
                        while(left < right && nums[left] == nums[left+1]) ++left;
                        while(left < right && nums[right] == nums[right-1]) --right;
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution18;
int main() {
    Solution solution = Solution();

    return 0;
}

