#include "../../../stdc.h"

using namespace std;

namespace solution349{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        // 仅仅只是查找数组中的元素是否会在两个集合中同时出现即可 —— 直接一个数组分析放入set, 另外一个数组元素查找是否在其中即可
        vector<int> res;
        unordered_set<int> search_set, res_set;
        for(auto i : nums1)
        {
            if(search_set.find(i) != search_set.end()) continue;
            else
                search_set.insert(i);
        }

        for(auto i : nums2)
        {
            if(search_set.find(i) != search_set.end()) res_set.insert(i);
        }

        for(auto i : res_set)
            res.push_back(i);
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution349;
int main() {
    Solution solution = Solution();

    return 0;
}
