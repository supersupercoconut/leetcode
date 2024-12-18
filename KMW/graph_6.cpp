/* 关于拓扑排序处理 */
// 拓扑排序主要分析的是顶点之间存在相互依赖关系 A->B 即对应B依赖与A，所以A必须先于B进行处理　
// 整体流程就是不断循环，找入度为0的点进行处理。如果没有找到可能是已经完成可以输出，也可能是出现了环即需要输出-1(对比结果集中的元素就可实现分析)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> inDegree(n,0);
    vector<int> res;
    vector<vector<int>> grid(n, vector<int>(n,0));
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
        inDegree[b]++;
    }


    // 每一次将一个节点放入结果集，故for循环最多处理n次
    for(int i = 0; i < n; ++i)
    {
        // 寻找入度为0的点
        int node = -1;
        for(int j = 0; j < inDegree.size(); ++j)
        {
            if(inDegree[j] == 0)
            {
                node = j;
                inDegree[j] = -1; // 使用过即修正成为-1
                res.push_back(node);
                break;
            }
        }
        // 判断是否可以退出 node == -1即没找到入度为-1的点
        if(node == -1)
        {
            cout << -1;
            return 0;
        }

        // 在图中删除该点对应的边
        for(int j = 0; j < n; ++j)
        {
            if(grid[node][j] != 0)
            {
                grid[node][j] = 0;
                inDegree[j]--;
            }
        }

    }

    for(int s = 0; s < n - 1; ++s)
        cout << res[s] << ' ';
    cout << res[res.size()-1] << endl;

    return 0;
}