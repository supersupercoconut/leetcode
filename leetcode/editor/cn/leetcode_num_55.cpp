#include "../../../stdc.h"
using namespace std;
namespace solution55{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 ) return false;
        /*** 在这里的判断不能进行跳步, 即 在i位置出前行nums[i] 但是在下一次 i+1位置前进nums[i+1]很可能会大于这个限制，所以需要用类似于一种遍历的方法来处理问题
         *   认为每一次都需要走最长距离的方法一旦commit就能分析出这是一种错误的解决方法
         *   ***/

        int cover = 0;          // cover的取值方式还是直接取index做判断
        for(int i = 0; i <= cover; ++i)
        {
            cover = cover > (i + nums[i]) ? cover : (i + nums[i]);
            if(cover >= nums.size()-1) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution55;
int main() {
    Solution solution = Solution();

    return 0;
}
