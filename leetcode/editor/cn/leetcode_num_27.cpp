#include "../../../stdc.h"

using namespace std;


namespace solution27{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 移除元素 - 利用双指针处理
    int removeElement(vector<int>& nums, int val)
    {
        int slow = 0;
        // 使用fast指针搜索所有不等于val的值
        for(int fast = 0; fast < nums.size(); ++fast)
        {
            if(nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        // 由于返回的是数组的size，故可以直接返回
        return slow;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution27;
int main() {
    Solution solution = Solution();

    return 0;
}
