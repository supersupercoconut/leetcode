// 卡码网 58 区间和
#include <iostream>
#include <vector>
using namespace std;
/* 实际处理比较简单，就是使用前缀表的方法保留之前叠加的结果，实现O(1)的复杂度 */
int main()
{
    int n = 0;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n; ++i)
        cin >> vec[i];

    // 生成前缀表
    int sum = 0;
    vector<int> next(n,0);
    for(int i = 0; i < n; ++i)
    {
        sum += vec[i];
        next[i] = sum;
    }

    // 接受输入的数据
    int a = 0, b = 0;
    while(cin >> a >> b)
    {
        if(a == 0) cout << next[b]<< endl;
        else
            cout << next[b] - next[a-1]  << endl;
    }

    return 0;
}
