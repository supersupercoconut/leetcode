#include "../../../stdc.h"
using namespace std;

namespace solution59{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int flag = 0;
    // 给定出发点以及每一条边的长度,以及开始遍历的值
    void traversal(vector<vector<int>>& grid, int start_x, int start_y, int n, int val)
    {
        if(n < 0)
            return;
        // 讨论奇偶变换
        if(n == 0)
        {
            if(flag == 0) return;
            grid[start_x][start_y] = ++val;
            return;
        }

        for(int i = 0; i < n; ++i)
            grid[start_x][start_y + i] = ++val;

        for(int i = 0; i < n; ++i)
            grid[start_x + i][start_y + n] = ++val;

        for(int i = 0; i < n; ++i)
            grid[start_x + n][start_y + n - i] = ++val;

        for(int i = 0; i < n; ++i)
            grid[start_x + n - i][start_y] = ++val;

        // 指定下一层循环(注意这里边的长度是-2变化的)
        traversal(grid, start_x + 1, start_y + 1, n-2, val);

    }


    vector<vector<int>> generateMatrix(int n)
    {
        // 利用回溯方法解决

        vector<vector<int>> res(n, vector<int>(n,0));
        if(n == 1)
            return {{1}};

        if(n % 2 == 0) flag = 0;
        else
            flag = 1;
        traversal(res, 0, 0, n-1, 0);

        for(auto i : res)
        {
            for(auto j : i)
                cout << j << " ";
            cout << endl;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution59;
int main() {
    Solution solution = Solution();

    return 0;
}
