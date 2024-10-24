#include "../../../stdc.h"

using namespace std;
namespace solution435{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    /***
     *  进一步解释 73 -26  | -65 -11  | -63 2  | -62 -49  | -52 31  | -40 -26  | -31 49  | 30 47  | 58 95  | 66 98  | 82 97  | 95 99 | 在这个例子中
     *  (1) 重叠部分需要选择right所在位置最小的区域 当(-62,-49)到来的时候 首先保证前面几个数据的left一定是小于这个-62的, 通过选择最小的right可以得到前面区间中的right一定是大于这个区间的right
     *      所以必然会出现交叉区域, 删除之前区域的操作一定没有问题
     * ***/

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // note 使用贪心的时候是直接到列举不出反例,不是忽略一些可能正常的需要考虑的部分
        sort(intervals.begin(), intervals.end(), compare);
        int res = 0;
        int right = right = intervals[0][1];;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(right > intervals[i][0])
            {
                // 如果出现重叠区域，那么直接找其对应部分 | 第一个元素相同的情况下，第二个元素小的在前面
                res++;
                right = min(right, intervals[i][1]);
            }
            else
                right = intervals[i][1];

        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution435;
int main() {
    Solution solution = Solution();
    vector<vector<int>> input = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout << solution.eraseOverlapIntervals(input);
    return 0;
}
