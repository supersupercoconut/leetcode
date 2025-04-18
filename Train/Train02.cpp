



//// 1、 有m个苹果，n个盘子，需要把这m个苹果放到n个盘子上， 求有多少种分配方法
//#include <iostream>
//using namespace std;
//
//int res = 0;
//void trversal(int m, int n, int index, int count)
//{
//    if(count == m)
//    {
//        res++;
//        return;
//    }
//
//    if(index >= n) return;
//    index++;
//
//    // 从剩余苹果中拿
//    for(int i = 0; i <= m - count; ++i)
//    {
//        trversal(m, n, index+1, count+i);
//    }
//}
//
//
//int main()
//{
//    int m = 10;
//    int n = 4;
//    trversal(m, n, 0, 0);
//    cout << res << endl;
//    system("pause");
//    return 0;
//}
//
//
