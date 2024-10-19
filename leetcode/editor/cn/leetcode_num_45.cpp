#include "../../../stdc.h"

using namespace std;
namespace solution45{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*** 1. 个人方法: 在判断时间复杂度上是有些复杂, 总感觉有些O(n^2)的可能行 ***/
//    int jump(vector<int>& nums) {
//        if(nums.size() == 1) return 0;
//        // 在判断上面 —— 确定可以找到nums[n-1], 并且还需要计算运动次数 | 这里没有引入向后跳转的概念(完全属于是自己的臆想)
//        int cover = nums[0];
//        /*** 这里还是采用了cover的取值概念, 但是会区分每一步中的cover取值变化(后面也会记录这部分的取值) ***/
//        int j = 1;
//        while(cover < (nums.size()-1) )
//        {
//            int temp = 0;
//            // 每一次在cover中开始遍历的元素下表 从0,1,2,...逐渐变化, 并且需要保证当前这一次的cover变换不会影响到当前正在遍历的情况
//            for(int i = j; i < nums.size() && i <= cover ; ++i)
//                temp = temp > (nums[i] + i) ? temp : (i + nums[i]);
//            cover = temp;
//            ++j;
//        }
//        // 最后输出的j就是实际结果
//        return j;
//    }

    /*** 2. 随想录中的方法， 这种方法就是纯正的O(n)， 只需要遍历一次，整个数组的数据就可以确定下来***/
    int jump(vector<int>& nums)
    {
        if(nums.size() == 1) return 0;
        // 在这里进行处理的过程中，上一步得到下一步应该可以遍历的最远范围，一旦超过这个范围，就得再使用一步
        int count = 0;
        int cover = 0;
        int second_cover = 0;
        // note 这里使用的遍历方法实在是太神奇了， 我之前相当于是写了两层for循环导致了很多不必要的重复数据出现，这里竟然一层遍历就实现了！！！
        for(int i = 0; i < nums.size(); ++i)
        {
            second_cover = second_cover > (nums[i] + i) ? second_cover : (nums[i] + i);
            if(i == cover)
            {
                count++;
                cover = second_cover;
                if(second_cover >= (nums.size()-1) ) break;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution45;
int main() {
    Solution solution = Solution();

    return 0;
}
