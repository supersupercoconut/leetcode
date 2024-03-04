#include "../../../stdc.h"

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
class Solution {
public:
/* 本体的思路如下
 * 1. 双指针: fast的内容覆盖slow内容, 与27移除元素的内容相似, fast先找到一个满足要求的元素，然后直接开始元素的覆盖，一直覆盖。出现两个空格的时候退过(这个时候一个空格也被复制过去了)
 * 2. 反转字符串: 自己写的函数中, string作为形参得使用引用才能保证修改的一致性
 * */
    string removeExtraSpaces(string& s)
    {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                && s[fastIndex - 1] == s[fastIndex]
                && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
        return s;
    }

    // 左闭右开 | 碰到的问题是字符串作为函数形参的话，得使用引用，否则在本函数中的修改都是无效操作
    string myReverse(string& s, int begin, int end)
    {
        int left = begin;
        int right = end-1;
        while(left < right)
            swap(s[left++],s[right--]);
        return s;
    }

    // 反转字符串
    string reverseWords(string s)
    {
        removeExtraSpaces(s);
        // 对全体进行反转
        myReverse(s,0,s.size());

        // 再对单一的单词进行反转 | reverse反转(左闭右开)
        int left = 0;
        int right = 0;
        while( right < s.size() )
        {
            if(s[right] != ' ') right++;
            else
            {
                myReverse(s,left, right);
                left = right+1;
                right++;
            }
        }
        // 退出循环，最后一个单词还没有反转
        myReverse(s,left,right);
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution151;
int main() {
    Solution solution = Solution();

    return 0;
}
