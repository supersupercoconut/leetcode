//import universal *.h
#include "../../../stdc.h"

using namespace std;
/* 回文字符串: 正读反读都是一样的字符串 */

namespace solution131{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /*** 这里复杂的部分主要有:
     *   1. 遍历切割方案(使用回溯) —— 这里的切割方法相当于对每次输入进来的字符串都判断到底切割几个字符(从少到多所有的切割方案都确定一下)
     *   2. 关于string的使用 —— 如何使用string中的substr方法
     *   3. 判断回溯
     * ***/
    vector<vector<string>> res = {};
    vector<string> path = {};
//    string temp = {};           // 保存临时结果

    bool isValid(string& s)
    {
        if(s.empty()) return false;
        int left = 0;
        int right = s.size()-1;
        while(left <= right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        // 说明遍历完成, 都是正常
        if(left > right) return true;
        return false;
    }

    /** 我一开始的思路是将整个字符串无脑切割了,然后从切割结果中判断其是不是回文串然后返回 —— 但这个实际使用应该要处理每一套切割方案中的所有字符串, 要求其必要全部都是子字符串 **/
    // substr() 两个参数 开始位置以及截止长度
    void backtracking(string& s, int start_index)
    {
        // 全部字符串都已经判断完成了, 这里才会将结果放置进去
        if(start_index >= s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; (start_index+i) < s.size() ;i++)
        {
            // start_index为本次字符串开始的位置 | i+1表示开始copy从start_index位置的字符(包含start_index)
            auto b = s.substr(start_index,i+1);
            if(isValid(b))
            {
                path.push_back(b);
                backtracking(s, start_index+i+1);
                path.pop_back();
            }
        }


    }


    vector<vector<string>> partition(string s)
    {
        if(s.empty()) return {};
        backtracking(s, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution131;
int main() {
    Solution solution = Solution();
    solution.partition("aab");

    return 0;
}

