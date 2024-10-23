#include "../../../stdc.h"
using namespace std;

namespace solution406{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*** 本问题从一开始我就没有读明白其对应的题意到底是什么
     *   [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]] 题目的问题是 重新构建这个队列，使其符合每一个people数组中对应的k(前面存在几个大于等于该身高的人)
     *   相当于从两个维度上来分析数据 ！ 先将高度从大到小进行排序（这样数据只会不断的往前插入），然后再将后续元素按照k值进行排序
     * ***/

    // note 没有想到在compare这个函数的部分可以这么设置 | 这里设置的compare可以将第一个元素相同的部分也同时完成设置
    static bool compare(vector<int>& a, vector<int>& b)
    {
        // 进行比较（true的时候是a>b，即对应的是降序排列）
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    // note 这部分神奇的部分在于按照身高先从大到小进行排序之后, 后续插入的元素都比之前插入的元素要小, 其并不会影响之前插入的部分(这里时间复杂度上的主要是vector中频繁插入元素导致的)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), compare);
        // 按照k进行排序
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); ++i)
        {
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution406;
int main() {
    Solution solution = Solution();

    return 0;
}
