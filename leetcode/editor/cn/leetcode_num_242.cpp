#include "../../../stdc.h"

using namespace std;


//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 
//输入: s = "rat", t = "car"
//输出: false 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s 和 t 仅包含小写字母 
// 
//
// 
//
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
//
// Related Topics 哈希表 字符串 排序 👍 970 👎 0


namespace solution242{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> res;
        for(auto i : s)
        {
            if(res.find(i) == res.end())
                res[i] = 1;
            else
                ++res[i];
        }

        for(auto i : t)
        {
            if(res.find(i) == res.end())
                return false;
            else
            {
                --res[i];
                if(res[i] < 0) return false;
            }
        }

        // 检查剩余数据是否全部为0
        for(auto i : res)
        {
            if(i.second != 0) return false;
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
