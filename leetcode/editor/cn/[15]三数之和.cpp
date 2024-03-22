#include "../../../stdc.h"
using namespace std;

namespace solution15{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 在同一个数组中寻找到三个元素| 元素之间的组合还是唯一的
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if(nums.empty())
            return {};
        // 先对数组进行排序
        sort(nums.begin(), nums.end());

        vector<vector<int>> result = {};
        // 使用双指针的方法进行操作
        for(int i = 0; i<nums.size() ; ++i)
        {
            if(nums[i] > 0)
                return result;
            // 对i进行判断并且去重 | 相同元素只判断最开始的那一个
            if(i>0 && nums[i] == nums[i-1])
                continue;
            // left与right 根据i的取值生成即可
            int left = i+1;
            int right = nums.size()-1;

            // 对于同一个i可能会对应许多成立的left与right取值 所以使用while | 因为i+1有可能超出数组边界，这里有right限制就没有问题
            while(left < right)
            {

                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                // 相等的情况下 | 单独改变right或者left的index值，下一次循环还是会改变left或者right的值，不如同时改变
                else
                {
                    result.push_back( {nums[i],nums[left],nums[right]} );

                    // 对left与right进行去重 | && 运算符如果左侧错误的话，就会不计算右侧的值直接返回false，可以防止 left = right而right有是在最后一个元素位置时，导致的越界问题
                    while(left < right && nums[left] == nums[left+1] ) left++;                   // 限制left不超范围
                    while(left < right && nums[right] == nums[right-1]) right--;                // 限制right不退后过分

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
    vector<int> temp = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    auto a = solution.threeSum(temp);
    for(auto i : a)
    {
        for(auto j : i)
            cout<<j<<',';
        cout<<endl;
    }
    return 0;
}
