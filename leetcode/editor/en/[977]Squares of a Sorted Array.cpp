//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given an integer array nums sorted in non-decreasing order, return an array 
//of the squares of each number sorted in non-decreasing order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-4,-1,0,3,10]
//Output: [0,1,9,16,100]
//Explanation: After squaring, the array becomes [16,1,0,9,100].
//After sorting, it becomes [0,1,9,16,100].
// 
//
// Example 2: 
//
// 
//Input: nums = [-7,-3,2,3,11]
//Output: [4,9,9,49,121]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums is sorted in non-decreasing order. 
// 
//
// 
//Follow up: Squaring each element and sorting the new array is very trivial, 
//could you find an 
//O(n) solution using a different approach?
//
// Related Topics Array Two Pointers Sorting 👍 8604 👎 213


namespace solution977{
    //leetcode submit region begin(Prohibit modification and deletion)
// 实现在特征条件下的排序方法，最后实现时间复杂度为O(n)，也就是将所有的元素都遍历了一遍，空间复杂度也是(n)
    class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            // nums如果为0，直接返回空数组
            vector<int> num_2 = nums;
            int left = 0;
            int right = nums.size()-1;
            int i = nums.size()-1;
            while( left < right )
            {
                int val1 = nums[left]*nums[left];
                int val2 = nums[right]*nums[right];

                if(val1<val2)
                {
                    num_2[i--] = val2;
                    right--;
                }
                else
                {
                    num_2[i--] = val1;
                    left++;
                }
            }

            // 结束while循环之后，left == right的时候，最后一个值的输出没有被更改
            num_2[0] = nums[left]*nums[left];
            return num_2;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution977;
int main() {
    Solution solution = Solution();

    return 0;
}



// 我一开始是想找到一个时间复杂度O(n), 空间复杂度O(1)的方法，但是目前这种代码里面是有Bug的，只能在部分的案例中实现正常排序(而且left指针一直是没有改变位置的，这可能也是问题的关键)
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums)
//    {
//        // 使用双指针来解决问题 | 或者使用快速排列的方式来解决问题
//        int left = 0;
//        int right = nums.size()-1;
//        int temp = 0;
//        // 取平方是为了后续比较
//        nums[left] = nums[left]*nums[left];
//
//        while(left < right)
//        {
//            // 只要进入比较环节，就直接取绝对值
//            // 因为left的位置一直没有变, 用于交换元素的时候，right的值已经进行了平方操作，就相当于所有的元素都进行了平方
//            nums[right] = nums[right]*nums[right];
//            if(nums[left] > nums[right])
//            {
//                temp = nums[right];
//                nums[right] = nums[left];
//                nums[left] = temp;
//            }
//            right--;
//
//        }
//        return nums;
//    }
//};