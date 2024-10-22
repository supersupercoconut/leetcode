#include "../../../stdc.h"

using namespace std;



namespace solution376{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 该问题即可以使用贪心的方法来解决，也可以使用动态规划 | 这里使用波峰与波谷的概念来解决问题
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return nums.size();
        int pre = 0;
        int cur = 0;
        int res = 1;
        // 默认>=3元素
        for(int i = 1; i < nums.size(); ++i)
        {
            /*** cur是判断当前这个i节点能不能成为这个波峰或者波谷 ***/
            cur = nums[i] - nums[i-1];
            // 存在两个元素并且不相等(对于只有两个元素或者是出现重复元素的情况也可以解决)
            if( (cur > 0 && pre <= 0) || (cur < 0 && pre >= 0) )
            {
                res ++;
                // 因为在实际使用中会出现相同元素,这里不能每一次都对pre进行更新
                pre = cur;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution376;
int main() {
    Solution solution = Solution();

    return 0;
}
