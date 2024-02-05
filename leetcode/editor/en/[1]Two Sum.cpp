//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given an array of integers nums and an integer target, return indices of the 
//two numbers such that they add up to target. 
//
// You may assume that each input would have exactly one solution, and you may 
//not use the same element twice. 
//
// You can return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// 
//
// Example 2: 
//
// 
//Input: nums = [3,2,4], target = 6
//Output: [1,2]
// 
//
// Example 3: 
//
// 
//Input: nums = [3,3], target = 6
//Output: [0,1]
// 
//
// 
// Constraints: 
//
// 
// 2 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// Only one valid answer exists. 
// 
//
// 
//Follow-up: Can you come up with an algorithm that is less than 
//O(n²)
// time complexity?
//
// Related Topics Array Hash Table 👍 54755 👎 1856


namespace solution1{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // 使用unordered_map的原因是即需要保存元素值又需要保存元素的标号 | vector与nums_map在初始化时都是size为0的状态
        unordered_map<int, int> nums_map = {};
        vector<int> result = {};
        for(int i = 0; i< nums.size(); ++i)
        {
            int temp = target - nums[i];
            // 如果能在result中找到对应元素
            if(nums_map.find(temp) != nums_map.end())
            {
                result.push_back(nums_map[temp]);   // 下标
                result.push_back(i);    // 下标
            }
            else
               nums_map.insert(make_pair(nums[i],i));
        }
        // 返回数据
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1;
int main() {
    Solution solution = Solution();

    return 0;
}
