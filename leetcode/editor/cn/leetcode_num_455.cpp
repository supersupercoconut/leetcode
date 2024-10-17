#include "../../../stdc.h"
using namespace std;


namespace solution455{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 1. 一个孩子只能得到一个饼干 2. 贪心算法对应的最优策略: 大的饼干有限给大的孩子
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return {};
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int res = 0;
        int j = g.size()-1;
        for(int i = s.size()-1; i >= 0;--i)
        {
            while(j >= 0 && g[j] > s[i] )
                j--;
            // 大于等于0 说明找到了能让当前s[i]满足的g
            if(j >= 0 )
            {
                j--;
                res++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution455;
int main() {
    Solution solution = Solution();

    return 0;
}
