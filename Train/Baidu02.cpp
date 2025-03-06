// 2023年 百度笔试 | 卡码网161. 讨厌鬼的组合帖子(非常简单, 直接获取值进行处理即可)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 直接利用贪心方法解决问题
    int n = 0;
    cin >> n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    vector<long> res(n, 0);
    for(int i = 0; i < n; ++i)
        res[i] = a[i] - b[i];

    // 两次遍历，选择所有正数以及所有负数相加和
    unsigned long long l = 0;
    unsigned long long r = 0;
    for(auto i : res)
    {
        if(i > 0)
            l += i;
        else
            r -= i;
    }

//    r = -r;
    r = r > l ?  r : l;
    cout << r  << endl;

    return 0;
}