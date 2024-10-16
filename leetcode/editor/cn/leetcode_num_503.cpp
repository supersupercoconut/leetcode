#include "../../../stdc.h"

using namespace std;

namespace solution503{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /*** 方法1: 本问题比较简单的方法就将数组进行扩充即在原始数组的基础上再拓展一个相同的数组
     *   方法2: 直接从序号的角度将数组进行拓宽, 并使用 % 来区分其是第一次遍历还是第二次遍历
     * ***/

    vector<int> res = {};
    stack<int> mystack = {};
    void traversal(vector<int>& nums)
    {
        res.assign(nums.size(), -1);
        mystack.push(nums[0]);
        /* 其使用的方法值不过是将序号拓展到原来的两倍， 并且在stack中保留的是之前的序号(如果新多出来的循环数据比之前在stack中的数据要大的话，其自己就会显示在res对应的部分) */
        for(int i = 1; i < nums.size() * 2; ++i)
        {
            if(nums[i % nums.size()] <= nums[mystack.top()])
                mystack.push(i % nums.size());
            else
            {
                while(nums[mystack.top()] < nums[i % nums.size()])
                {
                    res[mystack.top()] = nums[i % nums.size()];
                    mystack.pop();
                }
                mystack.push(i % nums.size());
            }
        }
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return {};
        traversal(nums);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution503;
int main() {
    Solution solution = Solution();

    return 0;
}
