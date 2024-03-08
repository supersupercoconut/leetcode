#include "../../../stdc.h"

using namespace std;


//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
// 
//
// 示例 2： 
//
// 
//输入：haystack = "leetcode", needle = "leeto"
//输出：-1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
//
// Related Topics 双指针 字符串 字符串匹配 👍 2166 👎 0


namespace solution28{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void getNext(int* next, const string& s)
    {
        next[0] = 0;
        int i = 1;
        int j = 0;
        while(i < s.size())
        {
            j = next[i-1];  // 使用j对字符串的对称性进行判断

            while(j>0 && s[j] != s[i])
                j = next[j-1];

            if(s[i] == s[j]) ++j;
            next[i] = j;
            ++i;
        }

    }

    // 使用提前生成的next数组进行匹配 | 并且在getNext的函数中使用了next[0],所以需要提前限制next数组的元素量
    int strStr(string haystack, string needle)
    {
        if(needle.empty())
            return 0;
        int next[needle.size()];
        // 生成next数组
        getNext(next,needle);

        int j = 0;
        for(int i = 0; i<haystack.size(); ++i)
        {
            if(haystack[i] == needle[j])
                j++;
            else if(j>0)
            {
                j = next[j-1];
                i--;            // 因为匹配不上应该 在原字符串上面的指针不应该移动,只移动j。所以先i--; | 因为这里i一定是大于等于1的，i--不会出现负数
            }

            // 但是为什么这里的i不需要i-- ，我知道加上会出现死循环，但是我从逻辑上还是认为应该加上的
            else j = 0;

            if(j == needle.size())
                return i-needle.size()+1;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution28;
int main() {
    Solution solution = Solution();
    cout<<solution.strStr("mississippi","issip");

    return 0;
}
