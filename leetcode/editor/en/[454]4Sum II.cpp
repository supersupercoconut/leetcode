//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, 
//return the number of tuples (i, j, k, l) such that: 
//
// 
// 0 <= i, j, k, l < n 
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0 
// 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
//Output: 2
//Explanation:
//The two tuples are:
//1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1)
// + 2 = 0
//2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1)
// + 0 = 0
// 
//
// Example 2: 
//
// 
//Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// n == nums1.length 
// n == nums2.length 
// n == nums3.length 
// n == nums4.length 
// 1 <= n <= 200 
// -2²⁸ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2²⁸ 
// 
//
// Related Topics Array Hash Table 👍 4849 👎 138


namespace solution454{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 最后输出的结果只是符合条件的元组数量(下标的排列顺序)，并不需要实际输出下标值 | 思路就是将AB CD分开计算，思路类似于两数之和
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        // A+B的取值变化可能大，所以不会使用数组来充当哈希结构(空间太浪费) | 不使用unordered_set也是因为需要去统计一个数量值，而且不需要去重 | 只能使用unordered_map
        // 遍历AB数组
        unordered_map<int,int> sumAB; // 第一个参数是A+B的计算结果，后一个是这个值出现的次数
        int result = 0;
        for(auto i : nums1)
        {
            for(auto j : nums2)
            {
                int temp = i + j;
                // 登记过这个元素
                if(sumAB.find(temp) != sumAB.end())
                   sumAB[temp] += 1;
                else
                    sumAB.insert(make_pair(temp, 1)); // 第一次
            }
        }

        // 遍历CD
        for(auto i : nums3)
        {
            for(auto j : nums4)
            {
                int temp = i + j;
                // 找到
                if(sumAB.find(-temp) != sumAB.end())
                    result += sumAB[-temp];
                // 是在计算CD数组加和的时候去判断，所以这里是+而不是乘(用乘的思路还要执行一个O(n)的操作)
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution454;
int main() {
    Solution solution = Solution();

    return 0;
}
