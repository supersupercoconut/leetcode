#include "../../../stdc.h"

using namespace std;


//给定一个非空的字符串
// s ，检查是否可以通过由它的一个子串重复多次构成。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abab"
//输出: true
//解释: 可由子串 "ab" 重复两次构成。
// 
//
// 示例 2: 
//
// 
//输入: s = "aba"
//输出: false
// 
//
// 示例 3: 
//
// 
//输入: s = "abcabcabcabc"
//输出: true
//解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 1 <= s.length <= 10⁴ 
// s 由小写英文字母组成 
// 
//
// Related Topics 字符串 字符串匹配 👍 1148 👎 0


namespace solution459{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 生成对应的next数组
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


    bool repeatedSubstringPattern(string s)
    {
        // 因为使用next数组的时候，会直接指定一个next[0]=0 | 所以需要提前保证next的元素不为空
        if(s.empty())
            return false;

        int next[s.size()];
        getNext(next, s);

        int temp = next[s.size()-1];
        // temp对应的是最大相等前后缀的数量 - 如果没有,那么就不会有重复性出现(因为next的数组的取值本身就代表了一种相似程度) | 如果有，再去分析能不能整除


        int result = s.size()-temp;  // 数量值
        if(s.size()%result == 0 && temp!=0)
            return true;
        else
            return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution459;
int main() {
    Solution solution = Solution();
    cout<<solution.repeatedSubstringPattern("abac");
    return 0;
}
