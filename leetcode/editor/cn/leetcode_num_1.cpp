#include "../../../stdc.h"
using namespace std;
namespace solution1{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // note 这里是使用 map 保留遍历之后的元素(一开始的想法是直接遍历完整个数组之后再开始处理) | 判断两个元素的加和是否等于target这个元素 - 并且只会输出一个vector结果
        unordered_map<int, int> search;
        vector<int> res = {};
        for(int i = 0; i < nums.size(); ++i)
        {
                auto a = search.find(target - nums[i]);
                if(a != search.end())
                {
                    return {a->second, i};
                }
                // 这里对一个map插入了相同的元素，但是map中insert方法并不是覆盖原有的值，而且本问题只需要一组返回结果故这部分可以直接忽略 ！！！
                search.insert({nums[i], i});
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution1;
int main() {
    Solution solution = Solution();

    return 0;
}
