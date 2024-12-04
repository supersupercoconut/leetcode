/*** 图论(主要整理代码随想录中的图论章节问题, 问题基本都是在卡码网上) ***/


/* 卡码网99 岛屿数量 */
#include <iostream>
#include <vector>
using namespace std;

int res = 0;
// 定义方向
int dir[4][2] = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
};


// 指定出发点(x,y) 终点(end_x, end_y) 以及当前地图graph, 访问地图visited
void bfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y, int cur_x, int cur_y)
{
    if(visited[cur_x][cur_y] == 1) return;
    else
        visited[cur_x][cur_y] = 1;

    int next_x = 0;
    int next_y = 0;
    if(graph[cur_x][cur_y] != 0)
    {
        for(auto temp : dir)
        {
            next_x = cur_x + temp[0];
            next_y = cur_y + temp[1];
            if(next_x >= 0 && next_x <= graph.size()-1 && next_y >= 0 && next_y <= graph[0].size()-1)
                bfs(graph, visited, x, y, next_x, next_y);
        }
        // 说明当前该出发点周围一圈的陆地都被发现了,可以直接输出res
        if(x == cur_x && y == cur_y) res += 1;
    }
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

    // 深度优先搜索
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            bfs(graph, visited, i, j, i, j);
        }
    }
    cout << res;
    return 0;
}






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