//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Write an algorithm to determine if a number n is happy. 
//
// A happy number is a number defined by the following process: 
//
// 
// Starting with any positive integer, replace the number by the sum of the 
//squares of its digits. 
// Repeat the process until the number equals 1 (where it will stay), or it 
//loops endlessly in a cycle which does not include 1. 
// Those numbers for which this process ends in 1 are happy. 
// 
//
// Return true if n is a happy number, and false if not. 
//
// 
// Example 1: 
//
// 
//Input: n = 19
//Output: true
//Explanation:
//1² + 9² = 82
//8² + 2² = 68
//6² + 8² = 100
//1² + 0² + 0² = 1
// 
//
// Example 2: 
//
// 
//Input: n = 2
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
//
// Related Topics Hash Table Math Two Pointers 👍 9946 👎 1367


namespace solution202{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculate(int n)
    {
        int sum = 0;
        // 将int的数据取出每一位数值 先%再/
        while( n != 0)
        {
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        // 然后对这个部分进行分析 如果不是一个happy数，那么这个数据就应该无限循环。我们所需要做的就是去在一个集合中查找这个元素是不是出现过，显然unorder_set更适合
        unordered_set<int> result;
        int temp = calculate(n);
        while( temp != 1 )
        {
            temp = calculate(temp);

            if( result.find(temp) == result.end() )
                result.insert(temp);
            else
                return false;
        }

        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution202;
int main() {
    Solution solution = Solution();

    return 0;
}
