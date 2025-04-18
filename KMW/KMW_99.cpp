#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count = 0;
vector<vector<int>> dir = {
        {1,0},
        {-1,0},
        {0,-1},
        {0,1}
};

// 广度有限搜索
void bfs(vector<vector<int>>& board, vector<vector<int>>& visited, int x, int y)
{
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x,y));
    int size = 1;
    // note 实际上这里是不需要维护一个size值的, 完全没有这种必要, 每次直接寻找即可
    while(!q.empty())
    {
        for(int i = 0; i < size; ++i)
        {
            auto tmp = q.front();
            q.pop();

            for(auto m : dir)
            {
                int next_x = tmp.first + m[0];
                int next_y = tmp.second + m[1];
                if(next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size())
                {
                    // 需要判断岛屿数量
                    if(visited[next_x][next_y] == 0 && board[next_x][next_y] == 1)
                    {
                        q.emplace(next_x, next_y);
                        visited[next_x][next_y] = 1;
                    }
                }
            }
            size = q.size();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m,0));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    }
    vector<vector<int>> visited(n, vector<int>(m,0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(visited[i][j]== 0 && board[i][j] == 1)
            {
                bfs(board, visited, i, j);
                count++;
            }
        }
    }

    cout << count << endl;
    system("pause");
    return 0;
}