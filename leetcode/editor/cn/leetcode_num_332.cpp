//import universal *.h
#include "../../../stdc.h"
using namespace std;


namespace solution332{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /** 本题不仅需要实现整体的逻辑, 还需要重建容器保存数据 **/
    // 这里使用unordered_map是想使用hash实现数据快速提取, 后面使用map是借助map自身的排序方式, 自动将字符串按照ASCII码进行排序 | 后续的pair类型数据就是map中的元素
    unordered_map<string, map<string,int>> targets = {};
    vector<string> path = {};
    // note 设置为bool可以方便函数快速退出
    bool backtracking(int ticket_num)
    {
        // ticket_num对应的是变的数量 所以这里对应+1正常
        if(path.size() == (ticket_num + 1) )
        {
            // path即返回值本身
            return true;
        }

        // 获取一个map, 这个map对应当前所有被找到的节点
        auto temp = targets[path.back()]; // 获取一个map
        // note 这里获取到 i 即为pair<string, int>类型 | 因为targets一旦形成之后,不需要删除元素了,所以这里设置一个int类型数据来表示从A到B是否还剩余票
        for(auto i : temp)
        {
            if(i.second != 0)
            {
                i.second--;
                path.push_back(i.first);
                if(backtracking(ticket_num)) return true;
                path.pop_back();
                i.second++;
            }
        }











//        auto temp = target[path.back()];
//        // i 对应 map<string,int>中的元素
//        for(auto i : temp)
//        {
//            path.push_back(i.first);
//            i.second--;
//            backtracking(ticket_num);
//            i.second++;
//            path.pop_back();
//        }




//        for (pair<const string, int>& target : targets[path[path.size() - 1]]) {
//            if (target.second > 0 ) { // 记录到达机场是否飞过了
//                path.push_back(target.first);
//                target.second--;
//                if (backtracking(ticket_num)) return true;
//                path.pop_back();
//                target.second++;
//            }
//        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty()) return {};
        // 整理tickets数据(这里是直接利用默认的初始化方法进行处理)
        for(auto i : tickets)
        {
            // 这里会直接先判断target中是否有 i[0], 再判断是否有i[1], 并且默认初始化后int对应的初始化数据为0，再执行++操作
            targets[i[0]][i[1]]++;
        }
        path.push_back("JFK");
        backtracking(tickets.size());
        return path;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution332;
int main() {
    Solution solution = Solution();

    return 0;
}

