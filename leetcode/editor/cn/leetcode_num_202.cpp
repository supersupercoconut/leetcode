#include "../../../stdc.h"

using namespace std;
namespace solution202{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isHappy(int n)
    {
        // 判断一个数是否是快乐数 - 感觉没有什么特别快的方法，需要穷举起来一遍一遍尝试
        // 利用hash表判断之前元素是否重复出现(利用set防止有元素重复出现)
        unordered_set<int> last;
        last.insert(n);
        unsigned int temp = n;
        while(1)
        {
            // note 这里实际上是可以不使用这个数组来保留所有的中间处理结果，可以直接计算累积值的，
            vector<int> res;
            while(temp / 10 != 0)
            {
                res.push_back(temp % 10);
                temp = temp / 10;
            }
            res.push_back(temp);

            // 分析当前元素
            temp = 0;
            for(auto i : res)
                temp += i * i;

            if(temp == 1) return true;
            if(last.find(temp) != last.end()) return false;
            last.insert(temp);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution202;
int main() {
    Solution solution = Solution();

    return 0;
}
