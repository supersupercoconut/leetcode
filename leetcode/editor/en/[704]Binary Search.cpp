//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given an array of integers nums which is sorted in ascending order, and an 
//integer target, write a function to search target in nums. If target exists, then 
//return its index. Otherwise, return -1. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-1,0,3,5,9,12], target = 9
//Output: 4
//Explanation: 9 exists in nums and its index is 4
// 
//
// Example 2: 
//
// 
//Input: nums = [-1,0,3,5,9,12], target = 2
//Output: -1
//Explanation: 2 does not exist in nums so return -1
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ < nums[i], target < 10⁴ 
// All the integers in nums are unique. 
// nums is sorted in ascending order. 
// 
//
// Related Topics Array Binary Search 👍 11345 👎 233


namespace solution704{
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution
    {
    public:
        int search(vector<int>& nums, int target)
        {
            // 左右边界(我这里的right永远不会被取到，所以当left = right的时候，一定不正常的现象，直接输出-1就行)
            int left = 0;
            int right = nums.size();
            while(left < right)
            {
                int middle = left + (right-left)/2;
                if(nums[middle] == target )
                    return middle;
                else if(nums[middle] > target)
                    right = middle;
                else
                    left = middle + 1;
            }
            return -1;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution704;
int main() {
    Solution solution = Solution();

    return 0;
}