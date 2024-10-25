#include "../../../stdc.h"
using namespace std;
namespace solution738{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 判断一个数字是不是递增数字
    bool isValid(int num)
    {
        int temp = num;
        int a = 0;
        // 最小数字
        while(temp > 0)
        {
            a = temp%10;
            temp /= 10;
            if(temp != 0 && temp%10 > a) return false;
        }
        return true;
    }

    // 这里返回最大数字
    int monotoneIncreasingDigits(int n) {
        /*** 暴力(超时) ***/
//        int res = 0;
//        for(int i = 0; i <= n; ++i)
//        {
//            if(isValid(i)) res = i;
//        }
//        return res;

        /*** 随想录上的暴力方法(只需找到最需要转换的部分然后后续部分全部转化为9) ***/
        string s = to_string(n);
        int flag = 0;
        for (auto i = s.size() - 1; i >= 1; --i) {
            if (s[i - 1] > s[i])
            {
                // 因为的s[i-1]一定是比s[i]要更大的,所以这里只需要数据比其大即可
                flag = i;
                s[i-1]--;
            }
        }

        // 遍历赋值为0
        if(flag != 0)
        {
            for(int i = flag; i < s.size(); ++i)
                s[i] = '9';
        }

        // 转换成为int类型
        return stoi(s);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution738;
int main() {
    Solution solution = Solution();
//    cout << solution.isValid(393457075);

    return 0;
}
