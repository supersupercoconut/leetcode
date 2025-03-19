#include "../../../stdc.h"
using namespace std;
namespace solution773{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // note 这种分析状态的问题与探索类型的问题最大的不一样在于, 白块出现的位置可以相同，只需要目前这个board的状态是不相同的即可
//    int flag = 0;
//    int min = 10000000;
//    int cur = 0;
//    vector<vector<int>> dir ={ {0,1}, {1,0}, {0,-1}, {-1,0} };
//    unordered_set<string> set;

//    void traversal(vector<vector<int>>& board, int start_x, int start_y)
//    {
////        if(visited[start_x][start_y] == 1) return;
//
//        // 当前board转换string 用于判断该状态是否已经出现
//        string s;
//        for(auto& i : board)
//            for(auto& j : i)
//                s += to_string(j);
//        if(set.find(s) != set.end()) return;
//        set.insert(s);
//
//        // 判断是否可以works
//        if(board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 &&
//           board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0)
//        {
//            min = min > cur ? cur : min;
//            flag = 1;
//            return;
//        }
//
////        visited[start_x][start_y] = 1;
//        for(auto tmp : dir)
//        {
//            int x = start_x + tmp[0];
//            int y = start_y + tmp[1];
//            if(x >= 0 && x <= 1 && y >= 0 && y <= 2)
//            {
////                if(visited[x][y] != 1)
////                {
//                    ++cur;
////                    swap(board[start_x][start_y], board[x][y]);
//                    swap(s[3*start_x + start_y], s[3*x+y]);
//                    traversal(board, x, y);
//                    set.erase(s);
////                    set.erase(s);
////                    visited[x][y] = 0;
//                    // 退出, 数据换回原位置
////                    swap(board[start_x][start_y], board[x][y]);
//                    swap(s[3*start_x + start_y], s[3*x+y]);
//                    --cur;
////                }
//            }
//        }
//    }


    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> visited(2, vector<int>(3,0));
        string s;
        for(auto& i : board)
        {
            for(auto& j : i)
            {
                s += to_string(j);
            }
        }

        string target = "123450";
        // note 这里相当于是一种简化思路, 后续需要对队列中获取到的每一个字符串都遍历查找'0'位置, 这样才能判断需要跟dir中的哪一个子数组进行交换
        vector<vector<int>> dir = {
            {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}
        };

        // 将每个状态都进行保留
        queue<string> q;
        unordered_set<string> set;
        q.push(s);
        set.insert(s);
        int start = 0;
        int flag = 0;
        int step = 0;
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][j] == 0)
                {
                    int size = 1;
                    while(!q.empty())
                    {
                        while(size--)
                        {
                            auto tmp = q.front(); q.pop();
                            // 遍历string找到0的位置
                            if(target == tmp)
                            {
                                flag = 1;
                                break;
                            }

                            for(int m = 0; m < tmp.size(); ++m)
                                if(tmp[m] == '0') start = m;

                            for(auto n : dir[start])
                            {
                                swap(tmp[start], tmp[n]);
                                if(set.find(tmp) == set.end())
                                {
                                    q.push(tmp);
                                    set.insert(tmp);
                                }
                                swap(tmp[start], tmp[n]);
                            }
                        }
                        size = q.size();
                        if(flag == 1) break;
                        step++;
                    }
                    if(flag == 1) return step;
                    else
                        return -1;
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution773;
int main() {
    Solution solution = Solution();
    vector<vector<int>> board = {{1,2,3}, {5, 4, 0}};
    cout << solution.slidingPuzzle(board);
    return 0;
}
