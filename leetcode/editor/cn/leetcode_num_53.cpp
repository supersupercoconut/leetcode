#include "../../../stdc.h"

using namespace std;

namespace solution53{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /* 1. 暴力算法: 比较复杂, 在每一个位置上都往后遍历, 定义一个res不断获取计算出的结果, 保证最后能获取到一个最大res即可
     * 2. 贪心: 贪心不太好弄明白的地方在于什么时候要结束当前计算res，碰到一个负数就退出绝对不行 (没有想到是计算这个连续和为负数的时候才需要重新更换计数)*/

    int maxSubArray(vector<int>& nums) {
    /*** 贪心方法 ***/
//        if(nums.empty()) return 0;
//        // 寻找连续子数组(不改变元素本身的位置, 并且保证在连续和出现负数的时候，才会重新开始计算res)
//        int res = 0x80000000;
//        int count = 0;
//        for(int i = 0; i < nums.size(); ++i)
//        {
//            if(count < 0) count = nums[i]; // 重新开始计算
//            else
//                count += nums[i];
//
//            // 更新res
//            res = res > count ? res : count;
//        }
//        return res;

    /*** 动规方法(整体比较简单，只需要确定dp定义就可以实现) ***/
        // dp[i] 0~i中 以nums[i]为结尾的最长连续子数组最大和
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            res = res > dp[i] ? res : dp[i] ;
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution53;
int main() {
    Solution solution = Solution();

    return 0;
}
