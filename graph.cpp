/*** 图论(主要整理代码随想录中的图论章节问题, 问题基本都是在卡码网上) ***/
#include <iostream>
#include <vector>
#include <list>
// vector表示图的保存方式为邻接矩阵 | list表示图的保存方式为邻接表
using namespace std;

vector<vector<int>> res = {};
vector<int> path = {};
// x为当前节点 n为目标节点
void bfs(const vector<vector<int>>& graph, int x, int n)
{
    if(x == n)
    {
        res.push_back(path);
        return;
    }

    // 因为这里的graph是直接按照序号来的，所以需要在一开始的基础上+1
    for(int i = 1; i < graph[x].size(); ++i)
    {
        if(graph[x][i] == 1)
        {
            path.push_back(i);
            bfs(graph,i,n);
            path.pop_back();
        }
    }
    return;
}


int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    // 构造邻接矩阵
    int a = 0, b = 0;
    while(m > 0)
    {
        cin >> a >> b;
        graph[a][b] = 1;
        --m;
    }

    path.push_back(1);
    bfs(graph,1,n);

    for(auto i : res)
    {
        for(int j = 0; j < i.size()-1; ++j)
            cout << i[j] << ' ';
        cout << i[i.size()-1];
        cout << endl;
    }
    if(res.size() == 0) cout << -1 << endl;
    return 0;
}