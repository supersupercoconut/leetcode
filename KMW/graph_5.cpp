/* prim方法实现最小生成树 */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//// 利用prim方法生成最小生成树 | 关于边的权重信息使用grid二维数组来保存
//int v = 0;
//int res = 0;
//vector<int> minDistance;
//vector<vector<int>> grid;
//void computeConnection(int node);
//
//int main()
//{
//    int e = 0;
//    cin >> v >> e;
//    minDistance.resize(v+1, 10000);
//    grid.resize(v+1, vector<int>(v+1, 0));
//
//    while(e--)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        grid[a][b] = c;
//        grid[b][a] = c;
//    }
//    // 从第一个节点开始运行
//    computeConnection(1);
//    cout << res;
//    return 0;
//}
//
//// 迭代计算最小值，对应的node为当前节点
//void computeConnection(int node)
//{
//    minDistance[node] = 0;
//    // 处理新来需要分析的点，并且更新misdistance数组
//    for(int i = 1; i <= v; ++i)
//    {
//        // 说明能连接
//        if(grid[node][i] != 0)
//            minDistance[i] = minDistance[i] <= grid[node][i] ? minDistance[i] : grid[node][i] ;
//    }
//
//    // 可视化mindistance
////    for(auto i : minDistance)
////        cout << i << ' ';
////    cout << endl;
//    //  更新其余顶点
//    int min = 10000;
//    int next_node = 0;
//    // 从minDistance数组中选择最小值
//    for(int i = 1; i <= v; ++i)
//    {
//        if(minDistance[i] == 0) continue;
//        if(min > minDistance[i])
//        {
//            min = minDistance[i];
//            next_node = i;
//        }
//    }
//    // 获取到当前的最小边带入计算 | 发现没有点可以加入即认为可以结束
//    if(next_node == 0) return;
//    res += min; // 获取最终输出
//    computeConnection(next_node);
//}

/* kruscal实现堆最小生成树 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
vector<int> father;
void init();
int find(int u);
bool isSame(int u, int v);
void join(int u, int v);

vector<vector<int>> grid;
bool compare(vector<int> a, vector<int> b);

int main()
{
    int e = 0;
    cin >> n >> e;
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >>c;
        grid.push_back({a,b,c});
    }
    // 边权重排序
    sort(grid.begin(), grid.end(), compare);

    // 最终处理过程
    int res = 0;
    init();
    for(auto i : grid)
    {
        int tmp_a, tmp_b;
        tmp_a = i[0];
        tmp_b = i[1];
        // 相等直接pass, 防止出现环
        if(isSame(tmp_a,tmp_b)) continue;
        join(tmp_a,tmp_b);
        res += i[2];
    }
    cout << res;
    return 0;
}


bool compare(vector<int> a, vector<int> b)
{
    if(a[2] >= b[2]) return false;
    return true;
}
/* 并查集实现 */
void init()
{
    father.resize(n+1);
    for(int i = 0; i <= n; ++i)
        father[i] = i;
}

int find(int u)
{
    return u == father[u] ? u : father[u] = find(father[u]);
}

bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v) return true;
    return false;
}

// 从u指向v, 将v指向u的father节点
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v) return;
    // u这里对应的是u这一路的根节点
    father[v] = u;
}