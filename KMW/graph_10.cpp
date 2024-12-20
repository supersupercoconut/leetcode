/* Astar方法求解(相当于是使用一种方法来对需要遍历的点进行排序, 优先选择更想选择的点) */

// note 统计一下本问题中出现的问题
/*
 *  (1) 优先级队列的处理方式 : 可以使用swap的方式快速清零整个队列数据 - 注意这里使用大顶堆还是小顶堆 | 因为权值是基于欧拉距离得到的，所以应该越小优先级越高
 *  (2) 关于每一个位置的权重计算 : 从当前点到终点的距离是预估可以直接计算，从起始点到当前点的距离是实际累积得到的
 *  (3) 关于每一个位置的步数计算 : 不能按照从队列弹出的步数进行计算，因为是类似于广度优先搜索的方法，所以得从cur到下一个点的所有步数都是直接加1的
 * */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Knight代表每一个骑士能运动的位置，每一个位置都将计算一个评价指标f，作为后续计算的根源
class Knight
{
public:
    // 位置
    int m_x = 0;
    int m_y = 0;
    // 计算指标
    int m_f = 0;
    int m_g = 0;
    int m_h = 0;

    Knight(){}
    Knight(int x, int y, int f, int g, int h) : m_x(x), m_y(y), m_f(f), m_g(g), m_h(h){}
};

// 重定义比较函数
class myComparison
{
public:
    // 小顶堆比较方式
    bool operator() (const Knight& a, const Knight& b)
    {
        return a.m_f > b.m_f;
    }
};

// 定义移动方向
int dir[8][2]
{
    {-2,-1},
    {-1,-2},
    {1,-2},
    {2,-1},
    {-2,1},
    {-1,2},
    {1,2},
    {2,1}
};


// 定义欧拉距离的计算公式 - 需要给定出发点与终点
int computeDistance(int x, int y, int x2, int y2);

int main()
{
    int n;
    cin >> n;
    int a1, a2, b1, b2;
    vector<vector<int>> query;
    while(n--)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        query.push_back({a1,a2, b1, b2});
    }

    // 分析每一个出发点到终点的最短路径
    priority_queue<Knight, vector<Knight>, myComparison> que;
    vector<vector<int>> moves(1001, vector<int>(1001, 0));
    for(auto i : query)
    {
        // 开始运动
//        int count = 0;
        int start_x = i[0];
        int start_y = i[1];
        int end_x = i[2];
        int end_y = i[3];

        // 计算当前的指标
        Knight knight_tmp;
        knight_tmp.m_x = start_x;
        knight_tmp.m_y = start_y;
        // m_g代表当前到起点的距离
        knight_tmp.m_g = 0;
        // m_h代表当前到终点的距离
        knight_tmp.m_h = computeDistance(start_x, start_y, end_x, end_y);
        knight_tmp.m_f = knight_tmp.m_g + knight_tmp.m_h;
        que.push(knight_tmp);

        while(!que.empty())
        {
            auto cur = que.top();
            que.pop();

            // 记录步数
            if(cur.m_x == end_x && cur.m_y == end_y) break;

            int next_x = 0;
            int next_y = 0;
            for(auto tmp : dir)
            {
                next_x = cur.m_x + tmp[0];
                next_y = cur.m_y + tmp[1];
                // 获取下一个行动点
                if(next_x >= 1 && next_x <= 1000 && next_y >= 1 && next_y <= 1000)
                {
                    if(moves[next_x][next_y] == 0)
                    {
                        moves[next_x][next_y] = moves[cur.m_x][cur.m_y] + 1;
                        // 计算f指标
                        Knight k;
                        k.m_x = next_x;
                        k.m_y = next_y;
//                    k.m_g = computeDistance(next_x, next_y, start_x, start_y);
                        k.m_g = cur.m_g + 5;
                        k.m_h = computeDistance(next_x, next_y, end_x, end_y);
                        k.m_f = k.m_g + k.m_h;
                        que.push(k);
                    }
                }
            }
        }

        // 结束循环之后, 直接分析是否正确
//        if(visited[end_x][end_y] == 1)
            cout << moves[end_x][end_y] << endl;

        // 对每一次循环之后处理掉整个队列
//        priority_queue<Knight> que_copy;
        priority_queue<Knight, vector<Knight>, myComparison> que_copy;
        vector<vector<int>> moves_copy(1001, vector<int>(1001,0));
        que.swap(que_copy);
//        while(!que.empty()) que.pop();
        moves.swap(moves_copy);
    }
    return 0;
}


int computeDistance(int x, int y, int x2, int y2)
{
    return (x-x2)*(x-x2) + (y-y2)*(y-y2);
}
