#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> dir = {
        {-1,2}, {-2,1}, {-2,-1}, {-1,-2},
        {1,2}, {2,1}, {2,-1}, {1,-2}
};

static int H(int a1, int a2, int b1, int b2)
{
    return (a1-b1)*(a1-b1) + (a2-b2)*(a2-b2);
}

struct Node
{
    int x, y;
    int f, g, h;
    Node() = default;
    Node(int a1, int a2) : x(a1), y(a2)
    {
        f = 0;
        g = 0;
        h = 0;
    }
};

class myCompare
{
public:
    // 小顶堆
    bool operator()(Node x, Node y)
    {
        if(x.f > y.f) return true;
        return false;
    }
};


int main()
{
    int n = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        vector<vector<int>> map(1001, vector<int>(1001, 0));
        priority_queue<Node, vector<Node>, myCompare> q;
        Node a(a1, a2);
        // f = g + h g为到沿移动路径到起始点的距离 h为当前点到终点的距离
        a.g = 0;
        a.h = H(a.x, a.y, b1, b2);
        a.f = a.g + a.h;
        q.push(a);
        map[a.x][a.y] = 1;

//        int count = 0;
        while(!q.empty())
        {
            auto tmp = q.top();
            q.pop();

            if(tmp.x == b1 && tmp.y == b2)
                break;

            for(auto m : dir)
            {
                int n_x = tmp.x + m[0];
                int n_y = tmp.y + m[1];
                if(n_x >= 1 && n_y >= 1 && n_x <= 1000 && n_y <= 1000)
                {
                    if(map[n_x][n_y] == 0)
                    {

                        Node c(n_x, n_y);
                        c.g = tmp.g + 5;
                        c.h = H(n_x, n_y, b1, b2);
                        c.f = c.g + c.h;
                        q.push(c);
                        // note 这个部分遇到的最大的bug就是计算路径数, 并不是每次pop元素之后就得+1, 而是从一点的下一步都属于第二步的范围
                        map[n_x][n_y] = map[tmp.x][tmp.y] + 1;
                    }
                }
            }
        }
        cout << map[b1][b2]-1 << endl;
    }
    system("pause");
    return 0;
}