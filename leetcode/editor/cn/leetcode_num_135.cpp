//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution135{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int candy(vector<int>& ratings)
    {
        if(ratings.empty()) return 0;
        if(ratings.size() == 1) return 1;
        // 相邻两个孩子评分高的可以获取更多的糖果

        // note 目前的困难在于递减序列的判断比较困难，比如3 3 2 2 1 比较困难地直接从3开始分发 | 随想录中给出来地算法就很巧妙 将整个流程转换为了两次遍历 前向遍历 + 后向遍历

        /* 1. 自己方法(错误)并没有考虑到 降序的情况，所以只相当于解决了其中一种的情况 */
//        int total = 0;
//        int pre_count = 0;
//        for(int i = 1; i < ratings.size(); ++i)
//        {
//            if(ratings[i] > ratings[i-1])
//            {
//                // 说明是刚开始的阶段
//                if(pre_count == 0)
//                {
//                    pre_count = 1;
//                    total += pre_count;
//                }
//                total += (pre_count + 1);
//                pre_count++;
//            }
//            else
//            {
//                if(pre_count == 0)
//                {
//                    pre_count = 2;
//                    total += pre_count;
//                }
//                total += 1;
//                pre_count = 1;
//            }
//        }
//        return total;

        /* 随想录中的方法(前后两种遍历) */
        // 这里应该只会考虑前向的一种情况
        vector<int> number = {};
        number.assign(ratings.size(),1);

        for(int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i] > ratings[i-1]) number[i] = number[i-1] + 1;
        }

        for(int i = ratings.size()-1; i >= 1 ;--i)
        {
            // 这里会出现其中一个元素 左侧比其小，右侧比起小 —— 会出现明明已经对应的数值在从前往后遍历中已经设置好了，但是从后往前的遍历中又可能对其重复设置
            if(ratings[i] < ratings[i-1] && number[i-1] <= number[i]) number[i-1] = number[i] + 1;
        }

        int total = 0;
        for(auto i : number)
            total += i;

        return total;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution135;
int main() {
    Solution solution = Solution();

    return 0;
}

