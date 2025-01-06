// 卡码网 44 开发商购买土地
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 一开始解决这个问题的时候并没有考虑到前缀表, 只是说提前计算好所有区间的值之和 - 虽然确实可以简化二维前缀表成为一维，这里就不再实现了 */
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    int sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
            sum += vec[i][j];
        }

    // 使用前缀表分析问题
    vector<vector<int>> next_row(n, vector<int>(m,0));
    vector<vector<int>> next_col(n, vector<int>(m,0));
    // 行分析
    int tmp = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            tmp += vec[i][j];
            next_row[i][j] = tmp;
        }
    }

    // 列分析
    tmp = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            tmp += vec[j][i];
            next_col[j][i] = tmp;
        }
    }

    // 穷举分析应该如何选择
    int min = 1724835450;
    for(int i = 0; i < n; ++i)
        min = min > abs(sum - 2 * next_row[i][m-1]) ? abs(sum - 2 * next_row[i][m-1]) : min;

    for(int j = 0; j < m; ++j)
        min = min > abs(sum - 2 * next_col[n-1][j]) ? abs(sum - 2 * next_col[n-1][j]) : min;

    cout << min << endl;
    return 0;
}

