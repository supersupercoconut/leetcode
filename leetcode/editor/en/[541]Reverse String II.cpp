//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given a string s and an integer k, reverse the first k characters for every 2
//k characters counting from the start of the string.
//
// If there are fewer than k characters left, reverse all of them. If there are
//less than 2k but greater than or equal to k characters, then reverse the first
//k characters and leave the other as original.
//
//
// Example 1:
// Input: s = "abcdefg", k = 2
//Output: "bacdfeg"
//
// Example 2:
// Input: s = "abcd", k = 2
//Output: "bacd"
//
//
// Constraints:
//
//
// 1 <= s.length <= 10⁴
// s consists of only lowercase English letters.
// 1 <= k <= 10⁴
//
//
// Related Topics Two Pointers String 👍 1900 👎 3691


namespace solution541{
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        // 这道题是使用了三个下表作为判断的依据 | i用于表示每一次循环开始的起始位置, j/m分别是k与2k的边界信息 | 最后在while()循环之后才会去进行逻辑判断，与题目中每一种情况进行匹配
        string reverseStr(string s, int k)
        {
            int i = 0;
            int j = 0;
            int m = 0;
            while(i<s.size())
            {
                // 在while()中直接循环出来相应的位置 | 循环结束 j为index = k处，m为index = 2k处 | m=s.size()认为这个循环找的刚刚好，不需要继续循环
                j = i;
                m = i;
                // 等于2k即认为可以退出循环了
                while(m-i<2*k)
                {
                    j+=1;
                    m+=2;
                }

                // 退出循环后，需要判断这时候j与m的位置在哪里
                if(m < s.size())
                    reverse(s.begin()+i, s.begin()+j);
                    // 后面两种情况中都是最后一次循环了
                else if(j >= s.size())
                {
                    reverse(s.begin()+i, s.end());
                    break;
                }
                else
                {
                    if( j-i < k )
                        reverse(s.begin()+i, s.begin()+j);
                    else
                        reverse(s.begin()+i, s.begin()+i+k);
                    break;
                }

                // 所有的区间都是左闭右开
                i = m;

            }
            return s;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution541;
int main() {
    Solution solution = Solution();

    return 0;
}
