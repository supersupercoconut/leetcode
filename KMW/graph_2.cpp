#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

// note 该问题本质上是从字符串序列构建成为一个图结构, 剩余部分的操作就是分析最短路径

unordered_map<string, vector<string>> adj = {};

// note 对应的遍历要分析当前出去该元素之外的所有怨怒是
void construct_adj(unordered_map<string, vector<string>>& _adj, vector<string>& strList)
{
    for(int i = 0; i < strList.size() - 1; ++i)
    {
        vector<string> string_list = {};
        for(int j = 0; j < strList.size(); ++j)
        {
            // 不能遍历自己, 但是需要遍历除去自己之外的所有元素
            if(j == i) continue;
            int sum = strList[j].size();
            // note 这里在一开始的理解出现了问题 是要在要求字符的顺序基础上, 还要有一个字符不同
            if(strList[i].size() != strList[j].size()) continue;
            else
            {
                for(int s = 0; s < strList[j].size(); ++s)
                {
                    if(strList[i][s] == strList[j][s]) sum--;
                }
            }
            if(sum == 1) string_list.emplace_back(strList[j]);
        }
        _adj[strList[i]] = string_list;
    }
}


int main()
{
    // 这里对应的cin操作相当于是会被空格或者回车间隔开进行处理
    int n = 0;
    cin >> n;

    vector<string> strList(n+2);
    cin >> strList[0] >> strList[n+1];

    for(int i = 0; i < n; ++i)
        cin >> strList[i+1];


    construct_adj(adj,strList);
    // 邻接表广搜
    int res = 1;
    // 记录每一层因该放入多少元素
    int count = 0;
    // 生成队列保留元素
    deque<string> que;
    for(auto i  : adj[strList[0]])
    {
        if(i == strList[n+1]) cout << res + 1;
        que.emplace_back(i);
        count ++;
    }

    while(!que.empty())
    {
        while(count >= 1)
        {
            auto node = que.front();
            que.pop_front();
            if(node == strList[n+1])
            {
                cout << res + 1;
                return 0;
            }

            res += 1;
            for(int i = 0; i < adj[node].size(); ++i)
            {
                if(adj[node][i] == strList[n+1])
                {
                    cout << res + 1;
                    return 0;
                }
                que.emplace_back(adj[node][i]);
            }
            res--;
            --count;

            cout << "que: " << que.size();
        }
        count = que.size();
        res++;
    }
    cout << res;
    return 0;
}