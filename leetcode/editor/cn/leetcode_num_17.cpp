//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution17{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<char,string> dict = {};
    void construct_dict()
    {
        dict.insert(pair<char,string>('2',"abc"));
        dict.insert(pair<char,string>('3',"def"));
        dict.insert(pair<char,string>('4',"ghi"));
        dict.insert(pair<char,string>('5',"jkl"));
        dict.insert(pair<char,string>('6',"mno"));
        dict.insert(pair<char,string>('7',"pqrs"));
        dict.insert(pair<char,string>('8',"tuv"));
        dict.insert(pair<char,string>('9',"wxyz"));
    }

    vector<string> res = {};
    string path = {};
    void backtracking(string& digits, int start_index)
    {
        if(start_index >= digits.size())
        {
            if(start_index == digits.size()) res.push_back(path);
            return;
        }

        // C++中提供了对于整个string的遍历方式 —— 直接定义下标处理即可
        string temp = dict[digits[start_index]];
        for(int i = 0; i < temp.size(); ++i)
        {
            // start_index 在这里只是提示应该遍历string数组中的下一个位置
            path += temp[i];
            // start_index作为函数的形参比全局变量表示起来要更简单一些
            backtracking(digits, start_index+1);

            // start为全局变量(需要给start_index不断的增减)
            // start_index++;
            // backtracking(digits,start_index);
            // start_index--;

            path.pop_back();
        }

    }

    // 由于给定的是字符串, 其对应的部分也是字符串，实际上是排列问题而不是组合问题
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};
        // 构造对应表
        construct_dict();
        // 回溯函数 | string的index从0开始
        backtracking(digits, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution17;
int main() {
    Solution solution = Solution();

    return 0;
}

