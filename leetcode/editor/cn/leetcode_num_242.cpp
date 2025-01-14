#include "../../../stdc.h"

using namespace std;
namespace solution242{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> res;
        for(auto i : s)
        {
            if(res.find(i) == res.end())
                res[i] = 1;
            else
                ++res[i];
        }

        for(auto i : t)
        {
            if(res.find(i) == res.end())
                return false;
            else
            {
                --res[i];
                if(res[i] < 0) return false;
            }
        }

        // 检查剩余数据是否全部为0
        for(auto i : res)
        {
            if(i.second != 0) return false;
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution242;
int main() {
    Solution solution = Solution();

    return 0;
}
