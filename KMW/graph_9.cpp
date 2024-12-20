/* 处理多个出发点问题(随想录中给出了从三维数据的角度来分析问题的过程) */
// note 这里主要是dp[]数组分析比较复杂
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<vector<int>>> grid(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 100000)));
    while(m--)
    {
        cin >> a >> b >> c;
        grid[a][b][0] = c;
        grid[b][a][0] = c;
    }

    // 输入需要求解的最短路径
    int q = 0;
    cin >> q;
    int start, end;
    vector<vector<int>> query;
    while(q--)
    {
        cin >> start >> end;
        query.push_back({start, end});
    }

    // 三层for循环
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                grid[i][j][k] = min(grid[i][k][k-1] + grid[k][j][k-1], grid[i][j][k-1]);
            }
        }
    }

    for(auto tmp : query)
    {
        // 没有路径
        if(grid[tmp[0]][tmp[1]][n] == 100000)
            cout << -1 << endl;
        else
            cout << grid[tmp[0]][tmp[1]][n] << endl;
    }
    return 0;
}