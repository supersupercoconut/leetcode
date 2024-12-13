#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    // 分析从1号节点能否到其他位置处(其属于是一种有向图，而且可能出现环)

    int n, k;
    cin >> n >>k;

    int t1 = 0, t2 = 0;
    unordered_map<int, vector<int>> adj = {};
    while(k--)
    {
        cin >> t1 >> t2;
        adj[t1].push_back(t2); // 这里没必要跟之前一样写这么复杂
//        if(adj.find(t1) == adj.end())
//        {
//            vector<int> temp(1,t2);
//            adj[t1] = temp;
//        }
//        else
//            adj[t1].push_back(t2);
    }


    // bfs处理搜索问题
    unordered_set<int> visited = {};
    deque<int> que = {};
    int count = 0; // 记录每一层的个数
    // 处理1号节点(不需要提前处理1号节点)
    visited.insert(1);
    que.push_back(1);

//    for(auto i : adj[1])
//    {
//        if(visited.find(i) == visited.end())
//        {
//            visited.insert(i);
//            que.push_back(i);
//            count++;
//        }
//        if(visited.size() == n)
//        {
//            cout << 1;
//            return 0;
//        }
//    }


    while(!que.empty())
    {
        // 这里的count也可以舍去不用, count在这里就是计算路径长度有用的变量,可惜不需要
        while(count--)
        {
            auto node = que.front();
            que.pop_front();
            for(auto i : adj[node])
            {
                if(visited.find(i) == visited.end())
                {
                    que.push_back(i);
                    visited.insert(i);
                }

//                if(visited.size() == n)
//                {
//                    cout << 1;
//                    return 0;
//                }
            }
        }
        count = que.size();
    }

    if(visited.size() == n) cout << 1;
    else
        cout << -1;
    return 0;
}