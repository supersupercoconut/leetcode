//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Write a function that reverses a string. The input string is given as an 
//array of characters s. 
//
// You must do this by modifying the input array in-place with O(1) extra 
//memory. 
//
// 
// Example 1: 
// Input: s = ["h","e","l","l","o"]
//Output: ["o","l","l","e","h"]
// 
// Example 2: 
// Input: s = ["H","a","n","n","a","h"]
//Output: ["h","a","n","n","a","H"]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s[i] is a printable ascii character. 
// 
//
// Related Topics Two Pointers String 👍 8194 👎 1145


namespace solution344{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        // 双指针 两两互换位置
        int left = 0;
        int right = s.size()-1;

        // 互换两个元素也可以使用swap库函数来进行
        while(left < right)
        {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution344;
int main() {
    Solution solution = Solution();

    return 0;
}
