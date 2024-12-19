/* 关于dijsktra处理 - 寻找最短路径(其只能解决非负的权值边问题) */
// note dijsktra方法与prim找最小生成的树的方法有些类似但是又不完全相同 - dijsktra中的minDistance[]保存的是其余点到出发点的距离是累计的，但是对于prim中的minDistance[]方法保存的是点到最小生成树的距离
//#include <iostream>
//#include <vector>
//#include <climits> // 用于 INT_MAX
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    // 初始化图的邻接矩阵，使用 INT_MAX 表示无穷大（不可达）
//    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
//    for (int i = 1; i <= n; ++i)
//        grid[i][i] = 0; // 自己到自己的距离为 0
//
//    // 读取边的信息
//    while (m--)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        grid[a][b] = c;
//    }
//
//    // Dijkstra 算法
//    vector<int> minDistance(n + 1, INT_MAX); // 起点到各节点的最短距离
//    vector<int> visited(n + 1, 0);          // 访问标记
//    minDistance[1] = 0;                     // 起点的距离为 0
//
//    for (int i = 1; i <= n; ++i)
//    {
//        // 找到未访问的最小距离节点
//        int minDist = INT_MAX, node = -1;
//        // note 只要minDistance中的数据不是最大值，即说明该节点一定可达，后续即可以从minDistance数组中选择出发位置
//        for (int j = 1; j <= n; ++j)
//        {
//            if (!visited[j] && minDistance[j] < minDist)
//            {
//                minDist = minDistance[j];
//                node = j;
//            }
//        }
//
//        // 如果找不到未访问的节点，说明剩下的节点不可达
//        if (node == -1) break;
//
//        visited[node] = 1; // 标记为已访问
//
//        // 更新邻居节点的距离
//        for (int j = 1; j <= n; ++j)
//        {
//            if (!visited[j] && grid[node][j] != INT_MAX)
//            {
//                // 这里对应的misDistance为累计的路径值
//                minDistance[j] = min(minDistance[j], minDistance[node] + grid[node][j]);
//            }
//        }
//    }
//
//    // 输出结果
//    if (minDistance[n] == INT_MAX)
//        cout << -1 << endl; // 如果终点不可达
//    else
//        cout << minDistance[n] << endl; // 输出最短路径长度
//
//    return 0;
//}

/* 针对边的数量较少的图实现(从堆的角度来解决问题) - 其中可以直接用我们自己定义的数据套用优先级队列 */
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

class Edge
{
    public:
        int node = 0;
        int weight = 0;
};

class myComparison
{
    public:
        // 小顶堆
        bool operator() (const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second > b.second;
        }
};


vector<list<Edge>> grid;
int main()
{
    int n,m;
    cin >> n >> m;
    int a, b, c;
    grid.resize(n + 1);

    Edge edge;
    // 实现邻接表保存从每一个节点开始的边
    while(m--)
    {
        cin >> a >> b >> c;
        edge.node= b;
        edge.weight = c;
        grid[a].emplace_back(edge);
    }

    // 定义距离数组与已访问点
    int start = 1;
    int end = n;
    vector<int> minDistance(n+1, INT_MAX);
    vector<int> visited(n+1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pq;
    pq.emplace(start,0);
    minDistance[start] = 0;
    // note 这里相比与之前的方法 是直接使用优先级队列保留到一个点的边。如果这个点在一开始的时候没有被选择，其在后续更新距离的时候出发点到该点的距离很可能会被更新掉，新加入的边如果权值比其小，会被优先级队列自动弹出使用。之前保留的数据会自动不用。
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        // 这里获取下一个移动到的点是否已经到达过
        if(visited[cur.first] == 1) continue;

        // 打印被使用点
//        cout << "next node: " << cur.first << endl;
        visited[cur.first] = 1;

        // 更新minDistance
        for(auto i : grid[cur.first])
        {
            if(visited[i.node] != 1)
            {
                // 对于没有被使用的点更新其到出发点的距离
                minDistance[i.node] = minDistance[i.node] > minDistance[cur.first] + i.weight ? minDistance[cur.first] + i.weight : minDistance[i.node];
                pq.emplace(i.node, minDistance[i.node]);
            }
        }

        // 打印misDistance
//        for(auto i : minDistance)
//            cout << i << " ";
//        cout << endl;

    }

    // 最后返回从end出发的部分
    if(minDistance[end] == INT_MAX)
        cout << -1;
    else
        cout << minDistance[end];

    return 0;
}