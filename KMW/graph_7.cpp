/* 关于dijsktra处理 - 寻找最短路径 */
// note dijsktra方法与prim找最小生成的树的方法有些类似但是又不完全相同

#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MAX
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // 初始化图的邻接矩阵，使用 INT_MAX 表示无穷大（不可达）
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; ++i)
        grid[i][i] = 0; // 自己到自己的距离为 0

    // 读取边的信息
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        grid[a][b] = c;
    }

    // Dijkstra 算法
    vector<int> minDistance(n + 1, INT_MAX); // 起点到各节点的最短距离
    vector<int> visited(n + 1, 0);          // 访问标记
    minDistance[1] = 0;                     // 起点的距离为 0

    for (int i = 1; i <= n; ++i)
    {
        // 找到未访问的最小距离节点
        int minDist = INT_MAX, node = -1;
        // note 只要minDistance中的数据不是最大值，即说明该节点一定可达，后续即可以从minDistance数组中选择出发位置
        for (int j = 1; j <= n; ++j)
        {
            if (!visited[j] && minDistance[j] < minDist)
            {
                minDist = minDistance[j];
                node = j;
            }
        }

        // 如果找不到未访问的节点，说明剩下的节点不可达
        if (node == -1) break;

        visited[node] = 1; // 标记为已访问

        // 更新邻居节点的距离
        for (int j = 1; j <= n; ++j)
        {
            if (!visited[j] && grid[node][j] != INT_MAX)
            {
                // 这里对应的misDistance为累计的路径值
                minDistance[j] = min(minDistance[j], minDistance[node] + grid[node][j]);
            }
        }
    }

    // 输出结果
    if (minDistance[n] == INT_MAX)
        cout << -1 << endl; // 如果终点不可达
    else
        cout << minDistance[n] << endl; // 输出最短路径长度

    return 0;
}