//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given an array nums of n integers, return an array of all the unique
//quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//
//
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
//
//
// You may return the answer in any order.
//
//
// Example 1:
//
//
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//
//
// Example 2:
//
//
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 200
// -10⁹ <= nums[i] <= 10⁹
// -10⁹ <= target <= 10⁹
//
//
// Related Topics Array Two Pointers Sorting 👍 10936 👎 1332


namespace solution18{
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        // 在实现该功能的时候，在这个测试样例下[1000000000,1000000000,1000000000,1000000000]出现了overflow的错误 | 即加法操作加的时候超出了其所能表示的最大范围
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            vector< vector<int> > result = {};
            sort(nums.begin(), nums.end());

            // 先写两个for()循环进行去重
            for(int i = 0; i < nums.size(); ++i)
            {
                // 对a去重
                if(i > 0 && nums[i] == nums[i-1])
                    continue;

                for(int j = i + 1; j < nums.size(); ++j)
                {
                    // 对b进行去重 | 总是感觉b的去重有点类似于left的去重
                    if( j-i > 1 && nums[j] == nums[j-1])
                        continue;

                    int left = j + 1;
                    int right = nums.size()-1;
                    while(right > left)
                    {
                        // 如果是四个大数直接相加的话，会超出int类型的数据范围 | 所以直接定义了一个long long来处理输出结果
                        long long temp = 0;
                        temp += nums[i];
                        temp += nums[j];
                        temp += nums[left];
                        temp += nums[right];

                        if(temp > target)
                            right--;
                        else if(temp < target)
                            left++;
                        else
                        {
                            // 放入数据结果
                            result.push_back( {nums[i], nums[j], nums[left], nums[right]} );
                            // 去left与right数据进行去重
                            while( right > left && nums[left] == nums[left+1]) left++;
                            while( right > left && nums[right] == nums[right-1] ) right--;
                            // 更新序号
                            right--;
                            left++;
                        }
                    }
                }
            }
            return result;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution18;
int main() {
    Solution solution = Solution();
    vector< vector<int> > a = {};
    vector<int> b = {0,0,0,1000000000,1000000000,1000000000,1000000000};
    a = solution.fourSum(b,1000000000);

    for(auto& i : a)
    {
        for(auto j : i)
            cout<<j<<' ';
        cout<<endl;
    }
    return 0;
}
