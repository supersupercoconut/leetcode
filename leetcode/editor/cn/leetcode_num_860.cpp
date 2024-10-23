#include "../../../stdc.h"

using namespace std;



namespace solution860{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool judge(unordered_map<int,int>& res, int tar)
    {
        if(tar == 0) return true;
        // 因为顾客给的钱一定是5 10 20 所以需要找零的钱数一定是 5 15两种
        if(tar == 5)
        {
            if(res[5] <= 0) return false;
            else res[5]--;
            return true;
        }
        else
        {
            // 对于 15 可以是 1张5 1张10 也可以是三张5(因为5的用处多，所以尽量是先使用10，最后再使用5)
            if(res[5] <= 0) return false;
            if(res[10] <= 0 && res[5] >= 3)
            {
                res[5] -= 3;
                return true;
            }
            else if(res[10] >= 1 && res[5] >= 1)
            {
                res[5] -= 1;
                res[10] -= 1;
                return true;
            }
            return false;

        }
    }

    bool lemonadeChange(vector<int>& bills) {
        /*** 本问题中贪心的策略出现的并不是那么明显，实际上就是把所有的情况讨论一遍就能发现规律 ***/
        unordered_map<int, int> res = {};
        res.insert(pair<int,int>(5,0));
        res.insert(pair<int,int>(10,0));
        res.insert(pair<int,int>(20,0));
        for(int i = 0; i < bills.size(); ++i)
        {
            // 判断能否找零
            if(!judge(res,bills[i]-5)) return false;
            res[bills[i]]++;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution860;
int main() {
    Solution solution = Solution();

    return 0;
}
