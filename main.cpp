#include "stdc.h"

using namespace std;


//Given an input string s, reverse the order of the words.
//
// A word is defined as a sequence of non-space characters. The words in s will
//be separated by at least one space.
//
// Return a string of the words in reverse order concatenated by a single space.
//
//
// Note that s may contain leading or trailing spaces or multiple spaces
//between two words. The returned string should only have a single space separating the
//words. Do not include any extra spaces.
//
//
// Example 1:
//
//
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//
//
// Example 2:
//
//
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing
//spaces.
//
//
// Example 3:
//
//
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single
//space in the reversed string.
//
//
//
// Constraints:
//
//
// 1 <= s.length <= 10⁴
// s contains English letters (upper-case and lower-case), digits, and spaces '
//'.
// There is at least one word in s.
//
//
//
// Follow-up: If the string data type is mutable in your language, can you
//solve it in-place with O(1) extra space?
//
// Related Topics Two Pointers String 👍 8001 👎 5059


namespace solution151{
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution{
    public:
        void getNext(int* next, const string& s)
        {
            next[0] = 0;
            int i = 1;
            int j = 0;
            while(i < s.size())
            {
                j = next[i-1];  // 使用j对字符串的对称性进行判断
//                if(s[j] == s[i]) next[i] = ++j;
//                else
//                {
//                    while(j>0 && s[j] != s[i])
//                        j = next[j-1];
//                    if(s[i] == s[j]) next[i] = ++j;
//                    else next[i] =0;
//                }
                while(j>0 && s[j] != s[i])
                    j = next[j-1];

                if(s[i] == s[j]) ++j;
                next[i] = j;
                ++i;
            }

            for(int i = 0; i<s.size(); ++i)
                cout<<next[i];

        }


//        int strStr(string haystack, string needle)
//        {
//            // 根据needle字符串生成一个next数组
//            int next[needle.size()];
//
//        }
    };
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution151;
int main() {
    Solution solution = Solution();

    int next[5];
    string s = "aaaac";
    solution.getNext(next,s);

    return 0;
}
