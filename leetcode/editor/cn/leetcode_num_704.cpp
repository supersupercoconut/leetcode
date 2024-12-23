#include "../../../stdc.h"
using namespace std;

namespace solution704{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 左闭右闭
    int binary(vector<int>& nums, int left, int right, int target)
    {
        int res = 0;

        // 判断单个元素 - 因为这里还没有对单个元素单不等于target的情况进行判断
        if(left == right)
        {
            if(target == nums[left]) return left;
            else
                return -1;
        }

        unsigned mid = (left + right)/2;
        if(target == nums[mid])
            return mid;
        else if(target < nums[mid])
            res = binary(nums, left,mid, target);
        else
            res = binary(nums, mid + 1, right, target);
        return res;
    }


    int search(vector<int>& nums, int target)
    {
        int res = 0;
        int left = 0;
        int right = nums.size() - 1;
        res = binary(nums, left, right, target);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution704;
int main() {
    Solution solution = Solution();

    return 0;
}
