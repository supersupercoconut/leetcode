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

/* Bellman_ford(遍历边版本) 解决出现负权回路的方法 */
//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//
//int main()
//{
//
//    int n, m;
//    cin >> n >> m;
//
//    int a, b, c;
//    vector<vector<int>> grid;
//    while(m--)
//    {
//        cin >> a >> b >> c;
//        // grid在这里只进行数据的保存
//        grid.push_back({a,b,c});
//    }
//
//    // 处理整体流程, 需要对所有的边都进行n次松弛 (无负权回路的方法只需要进行n-1次松弛)
//    vector<int> minDistance(n+1, INT_MAX);
//    int start = 1;
//    int end = n;
//    bool flag = false;
//    minDistance[start] = 0;
//    for(int i = 1; i <= n; ++i)
//    {
//        for(auto tmp : grid)
//        {
//            if(minDistance[tmp[0]] != INT_MAX)
//            {
//                // 修正距离矩阵
//                if(i < n)
//                    minDistance[tmp[1]] = minDistance[tmp[1]] > minDistance[tmp[0]] + tmp[2] ? minDistance[tmp[0]] + tmp[2] : minDistance[tmp[1]];
//                // 第n次处理
//                else
//                {
//                    // 使用相同的逻辑判断minDistance的数组元素是否会发生改变
//                    if(minDistance[tmp[1]] > minDistance[tmp[0]] + tmp[2]) flag = true;
//                }
//
//            }
//        }
//    }
//    if(flag) cout << "circle";
//    else if(minDistance[end] == INT_MAX) cout << "unconnected";
//    else
//        cout << minDistance[end];
//    return 0;
//}



/* Bellman_ford(队列优化版本) 解决出现负权回路的方法
 * 这部分处理队列比较复杂, 而且与之前没有出现负权回路的方法差别比较大
 * */




/* Bellman_ford 解决最短路径(加上了路径限制, 最多经过k个城市) */
// note 最多经过k个城市,相当于是限制了边的数量,从而也就限制了每次松弛之后能被修改的节点 - 因此这里copy了上次计算得到的minDistance数组(之前问题都不需要考虑这方面)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<int>> grid;

    while(m--)
    {
        cin >> a >> b >> c;
        grid.push_back({a,b,c});
    }

    int start, end, k;
    cin >> start >> end >> k;

    // 每对所有的边松弛一次，即对应从start开始一条边的最短路径被查找到
    vector<int> minDistance(n+1, INT_MAX);
    vector<int> minDistance_copy;
    minDistance[start] = 0;
    for(int i = 1; i <= k+1; ++i)
    {
        // 每一次松弛都需要从上次松弛的minDistance[]数组开始
        minDistance_copy = minDistance;
        for(auto tmp : grid)
        {
            if(minDistance_copy[tmp[0]] != INT_MAX)
                minDistance[tmp[1]] = minDistance[tmp[1]] > minDistance_copy[tmp[0]] + tmp[2] ? minDistance_copy[tmp[0]] + tmp[2] : minDistance[tmp[1]];
        }
        // 查找minDistance数组的变换情况
//        for(auto j : minDistance)
//            cout << j << " ";
//        cout << endl;
    }

    // 输出
    if(minDistance[end] != INT_MAX)
        cout << minDistance[end];
    else
        cout << "unreachable";

    return 0;
}







