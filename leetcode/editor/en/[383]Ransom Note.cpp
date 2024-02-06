//import universal *.h
#include "../../../stdc.h"

using namespace std;


//Given two strings ransomNote and magazine, return true if ransomNote can be 
//constructed by using the letters from magazine and false otherwise. 
//
// Each letter in magazine can only be used once in ransomNote. 
//
// 
// Example 1: 
// Input: ransomNote = "a", magazine = "b"
//Output: false
// 
// Example 2: 
// Input: ransomNote = "aa", magazine = "ab"
//Output: false
// 
// Example 3: 
// Input: ransomNote = "aa", magazine = "aab"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= ransomNote.length, magazine.length <= 10⁵ 
// ransomNote and magazine consist of lowercase English letters. 
// 
//
// Related Topics Hash Table String Counting 👍 4785 👎 485


namespace solution383{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 尝试使用匈牙利命名法来对变量进行命名
    // 这题因为是对字符进行分析，所以使用数组充当哈希结构是最简单的
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};
        // 有一个数在这里就加一
        for(auto i : magazine)
            count[(i-'a')] += 1;
        for(auto j : ransomNote)
        {
            count[(j-'a')] -= 1;
            if( count[(j-'a')] < 0)
                return false;
        }
        // 遍历完成 发现所有的ransomNote的字符都有对应则可以结束分析
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution383;
int main() {
    Solution solution = Solution();

    return 0;
}
