#include "../../../stdc.h"
using namespace std;

namespace solution56{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), compare);

        // note 能想到是使用list的方法固然是一种好的方法，但是这里直接再定义一个result数组就能直接分析虫胶
//        list<vector<int>> my_list = {};
//        for(int i = 0; i < intervals.size(); ++i)
//            my_list.push_back(intervals[i]);

        vector<vector<int>> res = {};
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i)
        {
            // 出现重叠部分，数据进入res | 判断当前res中的数据是不是与interval有交互区域
            if(res.back()[1] >= intervals[i][0] )
            {
                // note vector<int> temp = {}; 这里是创建了一个空的vector!! 不能对这部分的数据直接进行索引
                vector<int> temp = {};
                temp.push_back(res.back()[0]);
                temp.push_back(max(res.back()[1], intervals[i][1]));
                // 删除元素并且导入元素
                res.pop_back();
                res.push_back(temp);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution56;
int main() {
    Solution solution = Solution();

    return 0;
}
