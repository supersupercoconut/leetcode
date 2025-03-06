// 2023年 百度笔试 | 二分查找 + 差分数组 -> 差分数组就适合于一个数组中多个元素同时都是加上同一个值的情况, 但是需要判断是否超出阈值 所以引用一个二分查找的方法来解决该问题
#include <iostream>
#include <vector>
using namespace std;

// 判断当前处理过程中是否超出阈值 —— true就是超出阈值
bool isValid(vector<int>& a, vector<int>& diff, int n)
{
    vector<int> anger(n+1, 0);
    for(int i = 1; i <= n; ++i)
    {
        anger[i] = anger[i-1] + diff[i];
        if(anger[i] > a[i])
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, 0);
    vector<int> a(n+1, 0);

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<pair<int, int>> op(m + 1);
    for(int i = 1; i <= m; ++i)
    {
        int l = 0;
        int r = 0;
        cin >> l >> r;
        op[i] = pair<int, int>(l,r);
    }

    // note 这里怎么也没有想到二分法分开的竟然是操作的次数
    int left = 1;
    int right = m;
    int mid = 0;
    // res的默认值就是在全程没有超出其界限的部分，就直接返回最大值m
    int res = m;
    while(left <= right)
    {
        mid = left + (right - left)/2;
        vector<int> diff(n + 1,0);
        for(int i = 1; i <= mid; ++i)
        {
            auto l = op[i].first;
            auto r = op[i].second;
            diff[l] += 1;
            if(r + 1 < diff.size()) diff[r + 1] -= 1;
        }
        // 遍历之后，判断当前是否有人的愤怒值超过限制了
        if(isValid(a, diff, n))
            left = mid + 1;
        else
        {
            // 在mid处修改出现问题
            res = mid - 1;
            right = mid - 1;
        }
    }
    cout << res;
    return 0;

    // 差分数组
//    vector<int> p = v;
//    for(int i = 1; i <= m; ++i)
//    {
//        auto l = op[i].first;
//        auto r = op[i].second;
//        p[l] += 1;
//        if(r + 1 < p.size()) p[r + 1] -= 1;
//    }
//
//    vector<int> res = v;
//    for(int i = 1; i < p.size(); ++i)
//    {
//        // 最终获取到差分数组对应的数据
//        p[i] += p[i-1];
//        cout << p[i] << " ";
//    }

    return 0;
}

























/* 暴力求解方法 其只能在使用C++时通过所有的测试案列 */
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> v(n, 0);
//
//    // 输入n个整数表示数组a
//    vector<int> a = v;
//    for(int i = 0; i < n; ++i)
//        cin >> a[i];
//
//    int res = 0;
//    int flag = 0;
//    for(int i = 0; i < m; ++i)
//    {
//        if(flag == 0)
//        {
//            int l,r;
//            ++res;
//            cin >> l >> r;
//            for(int j = l - 1; j <= r - 1; ++j)
//            {
//                v[j]++;
//                if(v[j] > a[j])
//                {
//                    cout << res - 1 << endl;
//                    flag = 1;
//                }
//            }
//        }
//    }
//
//    if(flag == 0)
//        cout << m << endl;
//    return 0;
//}