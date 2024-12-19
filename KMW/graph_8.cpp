/* Bellman_ford 方法解决路径权值可能为负的情况，并找到一种自定义权值的的最短路径 */
//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    int a, b, c;
//    vector<vector<int>> grid;
//    while(m--)
//    {
//        // 由于直接处理边，所以可以直接将所有的边都保留下来，不使用邻接表/邻接矩阵处理
//        cin >> a >> b >> c;
//        grid.push_back({a,b,c});
//    }
//
//    // 一共n个点，对应的松弛次数为n-1
//    vector<int> minDistance(n + 1, INT_MAX);
//    int start = 1;
//    int end = n;
//    minDistance[1] = 0;
//    for(int i = 1; i < n; ++i)
//    {
//        // note 这里需要加上& 否则会超时 —— 毕竟每一次都需要拷贝所有的边是一件非常耗时的操作
//        for(auto& tmp : grid)
//        {
//            // 因为INT_MAX加上一个负数之后会变小，导致一个不能出发的点
//            if(minDistance[tmp[0]] != INT_MAX)
//                minDistance[tmp[1]] = minDistance[tmp[1]] > minDistance[tmp[0]] + tmp[2] ? minDistance[tmp[0]] + tmp[2] : minDistance[tmp[1]];
//        }
//
//        // debug minDistance的数组
////        for(auto t : minDistance)
////            cout << t << " ";
////        cout << endl;
//
//    }
//
//    if(minDistance[end] == INT_MAX)
//        cout << "unconnected";
//    else
//        cout << minDistance[end];
//
//    return 0;
//}


/* SPFA Bellman_ford的队列优化方法   */
//#include <iostream>
//#include <vector>
//#include <list>
//#include <deque>
//#include <climits>
//using namespace std;
//
//class Edge
//{
//    public:
//        int node = 0;
//        int weight = 0;
//};
//
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<list<Edge>> grid(n+1);
//    int a, b, c;
//    while(m--)
//    {
//        cin >> a >> b >> c;
//        grid[a].push_back(Edge{b,c});
//    }
//
//    vector<int> visited(n+1, 0);
//    vector<int> minDistance(n+1, INT_MAX);
//    deque<int> que;
//
//    int start = 1;
//    int end = n;
//    // note 这里注意: visited表示的是已经在队列中的元素不需要再被重复添加
//    que.push_back(start);
//    visited[start] = 1;
//    minDistance[start] = 0;
//    while(!que.empty())
//    {
//        // 取出当前数据
//        auto cur = que.front();
//        que.pop_front();
////        if(visited[cur] == 1) continue;
//        visited[cur] = 0;
//
//        // 判断当前节点能指向的节点，并且更新其对应的minDistance[]
//        for(auto i : grid[cur])
//        {
//            // 只判断已经被更新的部分
////            if(visited[i.node] == 0)
////            {
//                // 更新minDistance以及que
//                if(minDistance[i.node] > minDistance[cur] + i.weight)
//                {
//                    minDistance[i.node] = minDistance[cur] + i.weight;
//                    if(visited[i.node] == 0)
//                        que.push_back(i.node);
//                }
////            }
//        }
//    }
//
//    if(minDistance[end] == INT_MAX)
//        cout << "unconnected";
//    else
//        cout << minDistance[end];
//
//    return 0;
//}

/* 解决出现负权回路的方法 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    return 0;
}
