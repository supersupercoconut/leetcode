/*** 图论(主要整理代码随想录中的图论章节问题, 问题基本都是在卡码网上) ***/

/* 卡码网101 (孤岛的最大面积) 广度优先搜索 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int flag = 0;
int res = 0;
int temp_res = 0;
deque<pair<int,int>> que = {};
// 定义方向
int dir[4][2] = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
};


void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
{
    visited[x][y] = 1;
    if(graph[x][y] == 0)
        return;

    // 当前开始搜索的位置为graph中的1位置
    que.push_back(pair<int,int>(x,y));
    if(flag == 1)
        temp_res += 1;
    while(!que.empty())
    {
        auto node = que.front();
        que.pop_front();

        int next_x = 0;
        int next_y = 0;
        for(auto temp : dir)
        {
            next_x = node.first + temp[0];
            next_y = node.second + temp[1];
            if(next_x >= 0 && next_x <= graph.size() - 1 && next_y >= 0 && next_y <= graph[0].size() - 1)
            {
                if(visited[next_x][next_y] == 0)
                {
                    visited[next_x][next_y] = 1;
                    if(graph[next_x][next_y] == 1)
                    {
                        // 判断是否在边缘
                        if(next_x <= 1 || next_y <= 1 || next_x == graph.size() -1 || next_y == graph[0].size() - 1)
                        {
                            flag = 0;
                            temp_res = 0;
                        }
                        if(flag == 1)
                            temp_res += 1;
                        que.push_back(pair<int,int>(next_x,next_y));
                    }
                }
            }
        }
    }
    // 如果当前的队列为空, 即对应着一块岛屿面积就查找完毕了
//    cout << temp_res << endl;
    res += temp_res;
}


int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            cin >> graph[i][j];
    }


    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(visited[i][j] == 0)
            {
                // graph为0的时候,需要进入给visited赋值1
                if( i <= 1 || i == graph.size()-1 || j <= 1 || j == graph[0].size() - 1)
                    flag = 0;
                else
                    flag = 1;
                bfs(graph, visited, i, j);
                temp_res = 0;

            }
        }
    }
    cout << res;
    return 0;
}




/* 卡码网101 (孤岛的最大面积) 深度优先搜索 */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int flag = 0; // 用于判断res是否可以执行+1操作
//int res = 0;
//int temp_res = 0;
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
//{
//    if(visited[cur_x][cur_y] == 1) return;
//    else
//        visited[cur_x][cur_y] = 1;
//
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[cur_x][cur_y] != 0)
//    {
//        if(cur_x <= 1 || cur_x == graph.size()-1 || cur_y <= 1 || cur_y == graph[0].size()-1)
//        {
//            temp_res = 0;
//            flag = 0;
//        }
//
//        // 当前graph[][]为1, 说明这里没有查找到的过陆地
//        if(flag == 1)
//            temp_res += 1;
//        for(auto temp : dir)
//        {
//            next_x = cur_x + temp[0];
//            next_y = cur_y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, x, y, next_x, next_y);
//        }
//        // 当前节点的出发情况已经分析完毕, 即整理结果
//        if(cur_x == x && cur_y == y) res += temp_res;
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            flag = 1;
//            dfs(graph, visited, i, j, i, j);
//            temp_res = 0;
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网100 最大岛屿的面积(广度优先搜索) */
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int res = 0;
//int max_res = 0;
//deque<pair<int,int>> que = {};
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    visited[x][y] = 1;
//    if(graph[x][y] == 0)
//        return;
//
//    que.push_back(pair<int,int>(x,y));
//    res += 1;
//    while(!que.empty())
//    {
//        auto node = que.front();
//        que.pop_front();
//
//        int next_x = 0;
//        int next_y = 0;
//        for(auto temp : dir)
//        {
//            next_x = node.first + temp[0];
//            next_y = node.second + temp[1];
//            if(next_x >= 0 && next_x <= graph.size() - 1 && next_y >= 0 && next_y <= graph[0].size() - 1)
//            {
//                if(visited[next_x][next_y] == 0)
//                {
//                    visited[next_x][next_y] = 1;
//                    if(graph[next_x][next_y] == 1)
//                    {
//                        // 对应没有查找且是一块路基
//                        res += 1;
//                        que.push_back(pair<int,int>(next_x,next_y));
//                    }
//                }
//            }
//        }
//    }
//    // 如果当前的队列为空, 即对应着一块岛屿面积就查找完毕了
//    max_res = max_res > res ? max_res : res;
//    res = 0;
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            if(visited[i][j] == 0)
//            {
//                // graph为0的时候,需要进入给visited赋值1
//                bfs(graph, visited, i, j);
//            }
//        }
//    }
//    cout << max_res;
//    return 0;
//}


/* 卡码网100 最大岛屿的面积(深度优先搜索) */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int res = 0;
//int max_res = 0; // 用于衡量比较最大值
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
//{
//    if(visited[cur_x][cur_y] == 1) return;
//    else
//        visited[cur_x][cur_y] = 1;
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[cur_x][cur_y] != 0)
//    {
//        // 当前graph[][]为1, 说明这里没有查找到的过陆地
//        res += 1;
//        for(auto temp : dir)
//        {
//            next_x = cur_x + temp[0];
//            next_y = cur_y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, x, y, next_x, next_y);
//        }
//        // 说明当前该出发点周围一圈的陆地都被发现了,可以比较大小
//        if(x == cur_x && y == cur_y) max_res = max_res > res ? max_res : res;
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            dfs(graph, visited, i, j, i, j);
//            res = 0; // 执行完需要清空res的值
//        }
//    }
//    cout << max_res;
//    return 0;
//}


/* 卡码网99 岛屿数量(广度优先搜索) */
// note bfs与dfs最大的不同就是, dfs可以利用回溯剔除掉一些不合格的元素，但是bfs需要手动在队列输入的元素的时候就进行处理
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int res = 0;
//deque<pair<int,int>> que = {};
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//// 如果当前节点为graph为1 且当前visited为0 说明res可以+1
//void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y)
//{
//    visited[x][y] = 1;
//    if(graph[x][y] == 0)
//        return;
//
//    que.push_back(pair<int,int>(x,y));
//    while(!que.empty())
//    {
//        auto node = que.front();
//        cout << "que size():" << que.size() << endl;
//        que.pop_front();
//
//        int next_x = 0;
//        int next_y = 0;
//        for(auto temp : dir)
//        {
//            next_x = node.first + temp[0];
//            next_y = node.second + temp[1];
//            if(next_x >= 0 && next_x <= graph.size() - 1 && next_y >= 0 && next_y <= graph[0].size() - 1)
//            {
//                if(visited[next_x][next_y] == 0)
//                {
//                    visited[next_x][next_y] = 1;
//                    if(graph[next_x][next_y] == 1)
//                        que.push_back(pair<int,int>(next_x,next_y));
//                }
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            if(visited[i][j] == 0)
//            {
//                if(graph[i][j] == 1) res += 1;
//                // graph为0的时候,需要进入给visited赋值1
//                bfs(graph, visited, i, j);
//            }
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网99 岛屿数量(深度优先搜索) */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int res = 0;
//// 定义方向
//int dir[4][2] = {
//        {1,0},
//        {0,1},
//        {-1,0},
//        {0,-1}
//};
//
//
//// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
//void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
//{
//    if(visited[cur_x][cur_y] == 1) return;
//    else
//        visited[cur_x][cur_y] = 1;
//
//    int next_x = 0;
//    int next_y = 0;
//    if(graph[cur_x][cur_y] != 0)
//    {
//        for(auto temp : dir)
//        {
//            next_x = cur_x + temp[0];
//            next_y = cur_y + temp[1];
//            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
//                dfs(graph, visited, x, y, next_x, next_y);
//        }
//        // 说明当前该出发点周围一圈的陆地都被发现了,可以直接输出res
//        if(x == cur_x && y == cur_y) res += 1;
//    }
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//            cin >> graph[i][j];
//    }
//
//    // 深度优先搜索
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= m; ++j)
//        {
//            dfs(graph, visited, i, j, i, j);
//        }
//    }
//    cout << res;
//    return 0;
//}


/* 卡码网98 所有可达路径 */
//#include <iostream>
//#include <vector>
//#include <list>
//// vector表示图的保存方式为邻接矩阵 | list表示图的保存方式为邻接表
//using namespace std;
//
//vector<vector<int>> res = {};
//vector<int> path = {};
//// x为当前节点 n为目标节点
//void bfs(const vector<vector<int>>& graph, int x, int n)
//{
//    if(x == n)
//    {
//        res.push_back(path);
//        return;
//    }
//
//    // 因为这里的graph是直接按照序号来的，所以需要在一开始的基础上+1
//    for(int i = 1; i < graph[x].size(); ++i)
//    {
//        if(graph[x][i] == 1)
//        {
//            path.push_back(i);
//            bfs(graph,i,n);
//            path.pop_back();
//        }
//    }
//    return;
//}
//
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
//
//    // 构造邻接矩阵
//    int a = 0, b = 0;
//    while(m > 0)
//    {
//        cin >> a >> b;
//        graph[a][b] = 1;
//        --m;
//    }
//
//    path.push_back(1);
//    bfs(graph,1,n);
//
//    for(auto i : res)
//    {
//        for(int j = 0; j < i.size()-1; ++j)
//            cout << i[j] << ' ';
//        cout << i[i.size()-1];
//        cout << endl;
//    }
//    if(res.size() == 0) cout << -1 << endl;
//    return 0;
//}