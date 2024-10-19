#include "../../../stdc.h"

using namespace std;
namespace solution45{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        // 在判断上面 —— 确定可以找到nums[n-1], 并且还需要计算运动次数 | 这里没有引入向后跳转的概念(完全属于是自己的臆想)
        int cover = nums[0];
        /*** 这里还是采用了cover的取值概念, 但是会区分每一步中的cover取值变化(后面也会记录这部分的取值) ***/
        int j = 1;
        while(cover < (nums.size()-1) )
        {
            int temp = 0;
            // 每一次在cover中开始遍历的元素下表 从0,1,2,...逐渐变化, 并且需要保证当前这一次的cover变换不会影响到当前正在遍历的情况
            for(int i = j; i < nums.size() && i <= cover ; ++i)
                temp = temp > (nums[i] + i) ? temp : (i + nums[i]);
            cover = temp;
            ++j;
        }
        // 最后输出的j就是实际结果
        return j;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution45;
int main() {
    Solution solution = Solution();

    return 0;
}
