// note 这部分直接整理关于并查集的处理问题
#include <iostream>
#include <vector>
using namespace std;
// 设置vector数据 | 这里假设所有数据都是int类型的
//int n = 100; // 假设元素数量
vector<int> father;
// 生成并查集
int n = 0;
void init();
int find(int u);
void join(int u, int v);
bool isSame(int u, int v);
//void removeEdge(int u, int v);
void removeEdge(vector<vector<int>>& edge, vector<int>& degree);
void removeExternalEdge(vector<vector<int>>& edge);

int main()
{
/* 卡码网 107 寻找存在的路径*/
//    int m = 0;
//    cin >> n >> m;
//    // 修改容器大小, 即可实现init()函数中father[i] = i
//    father.reserve(n+1);
//    init();
//    // 读取m条边
//    for(int i = 0; i < m; ++i)
//    {
//        int u = 0, v = 0;
//        // 从v指向u
//        cin >> v >> u;
//        join(u, v);
//    }
//    int start = 0, end = 0;
//    cin >> start >> end;
//    cout << isSame(start,end);

/* 卡码网 108 冗余连接 */
//    int m = 0;
//    cin >> n;
//    m = n;
//    // 修改容器大小, 即可实现init()函数中father[i] = i
//    father.reserve(n+1);
//    init();
//    // 读取m条边
//    int res_a = 0, res_b = 0;
//    for(int i = 0; i < m; ++i)
//    {
//        int u = 0, v = 0;
//        // 从v指向u
//        cin >> v >> u;
//        // 新输入的边的节点不能在之前就加入到当前集合中
//        if(isSame(u,v))
//        {
//            res_a = v;
//            res_b = u;
//        }
//        // 两个节点已经连接起来之后就没必要再连接
//        else
//            join(u, v);
//    }
//    cout << res_a << " " << res_b;

/* 卡码网 109 冗余连接2(有向图使用较为复杂) */
/* 有向树的定义需要注意一下，根节点入度为0, 出度可以任意(这里是代码随想录中的解释) | 但是还有一种解释是不管其路径方向，只要是树结构，其就能说是一个有向树 */
    cin >> n;
    // index直接从1开始
    int s = 0, t = 0;
    vector<vector<int>> edge(n + 1,vector<int>(n + 1,0));
    vector<int> degree(n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> s >> t;
        edge[s][t] = 1;
        // t对应入度，数据只考虑入度
        degree[t]++;
    }
    removeEdge(edge, degree);



//    for(auto i : edge)
//    {
//        for(auto j : i)
//            cout << j << " ";
//        cout << endl;
//    }

    return 0;
}

// 判断删除一条边之后是否已经是一个正常无环图了
bool judgeValid(vector<vector<int>>& edge, int remove_a, int remove_b)
{
    father.reserve(n+1);
    init();

//    vector<vector<int>> inoutDegree(2, vector<int>(n+1,0));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(edge[i][j] == 1)
            {
                if(i == remove_a && j == remove_b) continue;
                if(isSame(i,j)) return false;
                else
                {
                    join(i,j);
//                    inoutDegree[0][i] ++;
//                    inoutDegree[1][j] ++;
                }
            }
        }
    }

    // 检测上述删除边之后会不会出现根节点不为1的情况
//    vector<vector<int>> inoutDegree(2, vector<int>(n+1,0));
//    for(int i = 1; i <= n; ++i)
//    {
//        for(int j = 1; j <= n; ++j)
//        {
//            if(edge[i][j] == 1)
//            {
//                if(i == remove_a && j == remove_b) continue;
//                // 0 出 1 入
//                inoutDegree[0][i] ++;
//                inoutDegree[1][j]++;
//            }
//        }
//    }

// 这部分处理并不必要，属于是对有向树理解有问题导致的
//    int count = 0;
//    for(int i = 1; i <= n; ++i)
//    {
//        if(inoutDegree[0][i] == 0 && inoutDegree[1][i] == 1)
//            count++;
//    }
//
//    if(count >= 2) return false;
    return true;
}

void removeExternalEdge(vector<vector<int>>& edge)
{
    father.reserve(n+1);
    init();
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(edge[i][j] == 1)
            {
                if(isSame(i,j))
                {
                    cout << i << " " <<j;
                    return;
                }
                else
                    join(i,j);
            }
        }
    }
    return;
}


// 删除一条边之后判断情况
void removeEdge(vector<vector<int>>& edge, vector<int>& degree)
{
    // 保存对应序号，并且该序号对应入度
    vector<int> node;
    for(int i = 0; i < degree.size(); ++i)
        if(degree[i] >= 2) node.emplace_back(i);

    for(int i = node.size()-1; i>=0 ; --i)
    {
        for(int j = n; j >= 1; --j)
//        for(int j = 1; j <= n; ++j)
        {
            // 尝试删除元素
            if(edge[j][node[i]] == 1)
            {
                // note 这里发现入度为2的两种情况同时别处理了 | 但是实际结果并不是如我分析的那样，我的程序出乎意料的能work 从原理上解释不通(目前感觉是卡码网给的测试案例可能忽略了这种情况)
                // 情况1/2 删除入度为2的任一边即可
                if(judgeValid(edge, j, node[i]))
                {
                    cout << j << " " << node[i];
                    return;
                }
            }
        }
    }
    // 如果当前没有入度为2的线, 即出现有向环的情况
    removeExternalEdge(edge);
}



void init()
{
    for(int i = 0; i <= n; ++i)
        father[i] = i;
}

// find()函数相当于是直接查找根 |  对于不在并查集中的元素, 其对应的father[]为自己本身，在集合中的元素对应的father在经过路径压缩之后应该是根节点
int find(int u)
{
    // 这里借助find()递归实现了路径压缩
    return u == father[u] ? u : father[u] = find(father[u]);
}


// note 在实际使用中, 集合中元素对应的父节点并不实际对应图中的其可能实际连接的根节点，所以join的时候是father[v]=u还是father[u]=v都是无所谓的
// 这里使用时相当于是从v存在指向u 即加入v->u这条边
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    // 相同的根节点
    if(u == v) return;
    // 注意这里u,v对应的都是自己的根节点
    father[v] = u;
}

bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v) return true;
    return false;
}
