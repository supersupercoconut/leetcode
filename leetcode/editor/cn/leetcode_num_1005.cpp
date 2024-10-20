#include "../../../stdc.h"

using namespace std;
namespace solution1005{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /***
     *  1. 自己的方法，一开始考虑不到的地方又很多，导致最后实现出来的代码加上了各种补丁，很冗余
     *
     * ***/
    // 在整个数组的改变上，k次的改变需要使用完毕
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());

        // 第一次遍历只会处理保证将能反转的负数全部反转
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }

        // 大于0 说明当前数组里面的元素已经全为正数，但是还存在k需要进行反转
        if(k > 0)
        {
            sort(nums.begin(), nums.end());
            while(k > 0)
            {
                k--;
                nums[0] = -nums[0];
            }
        }

        for(auto i : nums)
            res += i;

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1005;
int main() {
    Solution solution = Solution();
    vector<int> res = {-4,-2,-3};
    solution.largestSumAfterKNegations(res,4);
    return 0;
}
