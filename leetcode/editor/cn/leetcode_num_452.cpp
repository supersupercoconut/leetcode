#include "../../../stdc.h"
using namespace std;
namespace solution452{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 给定x轴上气球对应的区域，选择弓箭数将其射穿
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), compare);
        int count = 1;

        // 分析左右边界的思路是正确的, 忽略的问题是左右边界数据更新有一些不合理, 应该是每次循环出元素之后都需要设置更新右边界, 左边界自然就是当前遍历元素的points[i][0]
        int right_value = points[0][1];
        for(int i = 0; i < points.size(); ++i)
        {
            if(points[i][0] > right_value )
            {
                count++;
                right_value = points[i][1];     // points[i][0]大于right_value, 那么其对应的points[i][1]也一定大于这部分
            }
            right_value = min(right_value, points[i][1]);
        }
        return count;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}


using namespace solution452;
int main() {
    Solution solution = Solution();

    return 0;
}
