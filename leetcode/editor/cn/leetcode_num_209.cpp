//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution209{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int min_length = INT_MAX;

        for(; right < nums.size(); ++right)
        {
            sum += nums[right];
            while(sum >= target)
            {
                // 不存在left与right相等的情况
                min_length = min_length > right - left ? right - left : min_length;
                sum -= nums[left];
                ++left;
            }
        }

        if(min_length == INT_MAX) return 0;
        // 找元素个数要+1
        return min_length + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution209;
int main() {
    Solution solution = Solution();
    vector<int> tmp = {2,3,1,2,4,3};
    solution.minSubArrayLen(7,tmp);
    return 0;
}

