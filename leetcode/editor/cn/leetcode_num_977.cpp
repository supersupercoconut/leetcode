#include "../../../stdc.h"

using namespace std;

namespace solution977{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 比较巧妙的一种方法 利用双指针从两端开始比较
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> result(nums.size(), 0);
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;
        while(i <= j && k >= 0)
        {
            if(nums[i]*nums[i] < nums[j]*nums[j])
            {
                result[k--] = nums[j]*nums[j];
                j--;
            }
            else
            {
                result[k--] = nums[i]*nums[i];
                i++;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution977;
int main() {
    Solution solution = Solution();
    vector<int> tmp = {-4,-1,0,3,10};
    solution.sortedSquares(tmp);
    return 0;
}
