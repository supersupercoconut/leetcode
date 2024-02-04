//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given two strings s and t, return true if t is an anagram of s, and false 
//otherwise. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a 
//different word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
// Input: s = "anagram", t = "nagaram"
//Output: true
// 
// Example 2: 
// Input: s = "rat", t = "car"
//Output: false
// 
// 
// Constraints: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s and t consist of lowercase English letters. 
// 
//
// 
// Follow up: What if the inputs contain Unicode characters? How would you 
//adapt your solution to such a case? 
//
// Related Topics Hash Table String Sorting 👍 11632 👎 372


namespace solution242{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 这里提到的这个anagram指的就是字母种类与个数全部相同。本题就是在判断这两个字符串是不是anagram
    bool isAnagram(string s, string t)
    {
        int sum[26] = {0};
        for(auto i : s)
            sum[ (i-'a')] += 1;
        for(auto i : t)
        {
            sum[(i - 'a')] -= 1;
            // 提前终止
            if(sum[(i - 'a')] < 0 )
                return false;
        }
        // 判断是否全0
        for(auto i : sum)
        {
            if(i > 0) return false;
        }
         return true;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution242;
int main() {
    Solution solution = Solution();

    return 0;
}
