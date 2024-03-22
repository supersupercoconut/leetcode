#include "../../../stdc.h"
using namespace std;

namespace solution18{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 与15是相同的思路，双指针只能减小O(n)的复杂度 | 三数之和将复杂度从O(n^3)转换为O(n^2), 四数之和将复杂度从O(n^4)转换为O(n^2)
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if(nums.empty())
            return {};
        // 升序排列
        sort(nums.begin(), nums.end());

        vector<vector<int>> result = {};
        for(int i = 0; i<nums.size(); ++i)
        {
            // 如果对应的target为负数, 所以变换上要注意
            if(nums[i] > target && nums[i]>0)
                break;
            // 对i去重
            if(i>0 && nums[i] == nums[i-1])
                continue;

            for(int j = i+1; j<nums.size(); ++j)
            {
                if(nums[i]+nums[j] >target && nums[i] + nums[j]>0)
                    break;                  // 因为后面的都是不满足条件的
                if(j-i>1 && nums[j] == nums[j-1])
                    continue;
                // 之后的部分是双指针
                int left = j+1;
                int right = nums.size()-1;

                // 对于同一个i可能会对应许多成立的left与right取值 所以使用while | 因为i+1有可能超出数组边界，这里有right限制就没有问题
                while(left < right)
                {
                    if( (long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if( (long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                        // 相等的情况下 | 单独改变right或者left的index值，下一次循环还是会改变left或者right的值，不如同时改变
                    else
                    {
                        result.push_back( {nums[i], nums[j], nums[left], nums[right]} );
                        // 对left与right进行去重 | && 运算符如果左侧错误的话，就会不计算右侧的值直接返回false，可以防止 left = right而right有是在最后一个元素位置时，导致的越界问题
                        while(left < right && nums[left] == nums[left+1] ) left++;                   // 限制left不超范围
                        while(left < right && nums[right] == nums[right-1]) right--;                // 限制right不退后过分
                        left++;
                        right--;
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
    vector<int> temp = {0,0,4,-2,-3,-2,-2,-3};
    auto a = solution.fourSum(temp, -1);
    for(auto i : a)
    {
        for(auto j : i)
            cout<<j<<',';
        cout<<endl;
    }

    return 0;
}
