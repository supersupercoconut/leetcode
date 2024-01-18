//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given an array of positive integers nums and a positive integer target, 
//return the minimal length of a subarray whose sum is greater than or equal to target. 
//If there is no such subarray, return 0 instead. 
//
// 
// Example 1: 
//
// 
//Input: target = 7, nums = [2,3,1,2,4,3]
//Output: 2
//Explanation: The subarray [4,3] has the minimal length under the problem 
//constraint.
// 
//
// Example 2: 
//
// 
//Input: target = 4, nums = [1,4,4]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: target = 11, nums = [1,1,1,1,1,1,1,1]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= target <= 10⁹ 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁴ 
// 
//
// 
//Follow up: If you have figured out the 
//O(n) solution, try coding another solution of which the time complexity is 
//O(n log(n)).
//
// Related Topics Array Binary Search Sliding Window Prefix Sum 👍 12131 👎 388


namespace solution209{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 主要是对于O(n)的时间复杂度的判断方式有些困难 —— 随想录里面给了一个解释比较好，根据这个数组中的所有元素都至多被处理两次(进入窗口一次|弹出窗口一次)，则复杂度为O(n)
        // 引入的这个while循环中, 指挥进行元素的弹出操作，而且弹出一次之后，元素再也不会被滑动窗口接纳
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int i = 0;
        int result = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            // 每次进入for循环的时候，都是在之前的滑动窗口中找到了一个最小长度的时候
            sum += nums[j];
            while(sum >= target)        // 第一次自己写的时候，经常想写一些if判断条件来判断，这些方式都没有下面的方法写的简单，尤其是这个三目运算符的使用
            {
                subLength = j-i+1;
                result = result > subLength ? subLength : result;
                sum -= nums[i++];
            }
        }
        return result==INT32_MAX ? 0 : result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution209;
int main() {
    Solution solution = Solution();
    int target = 4;
    vector<int> nums = {1,4,4};
    std::cout<<solution.minSubArrayLen(target,nums);
    return 0;
}