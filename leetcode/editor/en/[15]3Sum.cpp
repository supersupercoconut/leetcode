//import universal *.h
#include "stdc.h"

using namespace std;


//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[
//k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.
//
//
// Example 1:
//
//
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Explanation:
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//The distinct triplets are [-1,0,1] and [-1,-1,2].
//Notice that the order of the output and the order of the triplets does not
//matter.
//
//
// Example 2:
//
//
//Input: nums = [0,1,1]
//Output: []
//Explanation: The only possible triplet does not sum up to 0.
//
//
// Example 3:
//
//
//Input: nums = [0,0,0]
//Output: [[0,0,0]]
//Explanation: The only possible triplet sums up to 0.
//
//
//
// Constraints:
//
//
// 3 <= nums.length <= 3000
// -10⁵ <= nums[i] <= 10⁵
//
//
// Related Topics Array Two Pointers Sorting 👍 29794 👎 2724


namespace solution15{
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        // 随想录中提示的想法是如果想使用哈希表来解决这个问题的话，在去重的部分比较麻烦需要自己手动去重
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            // 先将整个数组变得有序
            sort(nums.begin(), nums.end());   // STL中很方便的排序方法 | 升序排列
            // 需要返回的数据
            vector< vector<int> > result = {};
            // 这样是两个循环 O(n*n)
            for(int i = 0; i<nums.size(); ++i)
            {
                // 首先对a进行去重 | 这里写成与后面的while循环的形式也是一样的,只不过需要注意一个地方就是对于[0,0,0,0]的时候写成while得先让第一个符合条件的输入到result之后，才能开始去重(实际上不断地在这里使用continue就是while的效果)
                if( i>0 && nums[i] == nums[i-1] )
                    continue;

                int left = i + 1;
                int right = nums.size() - 1;
                // 如果直接是left = right, 那么就直接退出循环，必不可能得到合格的三个下标
                while(right > left)
                {
                    if(nums[i] + nums[left] + nums[right] > 0)
                        right--;
                    else if(nums[i] + nums[left] + nums[right] < 0)
                        left++;
                    else
                    {
                        // 相等的时候需要手动进行操作，防止一直在这个循环中出不来(也不能直接break因为还可能有其他的符合条件的组合)
                        result.push_back( {nums[i], nums[left], nums[right]} );

                        // 手动去重 | 因为这个元组中保存的元素是实际的元素值，并不是下标值，所以如果存在相同的元素值，那么它们的序号虽然不同，但是元素值还是重复的
                        while(right > left && nums[left] == nums[left+1])
                            left++;
                        // 这么写的好处 第一次nums[right]取值是被正常存放的，但是退出while的时候，现在是最后一次与nums[right]相等的值，所以最后在执行right--脱离出相等元素
                        while(right > left && nums[right] == nums[right-1])
                            right--;
                        // 更新序号 | 因为此时已经相加为0了, 如果只变换left或者right，这个等于关系就被打破了，单纯变换一个在下一次循环中还会变换另一个，所以不如直接在这里变化
                        left++;
                        right--;
                    }
                }
            }
            return result;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution15;
int main() {
    Solution solution = Solution();
    vector< vector<int> > a = {};
    vector<int> b = {-1, 0, 1, 2, -1, -4};
    a = solution.threeSum(b);

    for(auto i : a)
    {
        for(auto j : i)
            cout<<j<<' ';
        cout<<endl;
    }

    return 0;
}
