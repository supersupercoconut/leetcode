//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given two integer arrays nums1 and nums2, return an array of their 
//intersection. Each element in the result must be unique and you may return the result in 
//any order. 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
// 
//
// Example 2: 
//
// 
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums1.length, nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 1000 
// 
//
// Related Topics Array Hash Table Two Pointers Binary Search Sorting 👍 5497 👎
// 2231


namespace solution349{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 交集: 有相同的元素即可以认为是交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {

        unordered_set<int> result;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for(auto i : nums2)
        {
            if(nums1_set.find(i) != nums1_set.end())
                result.insert(i);
        }
        vector<int> result_vector(result.begin(), result.end());
        return result_vector;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution349;
int main() {
    Solution solution = Solution();

    return 0;
}
