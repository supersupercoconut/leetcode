//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution93{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> res = {};
    vector<string> path = {};

    /*** 整体思路上与131基本上是一样的，只是一些小的逻辑上不断打补丁 ***/
    bool isValid(string& s)
    {
        // 不能还有前导0(要么只有一个0，要么就是还有其他元素)
        if(s[0] == '0')
        {
            if(s.size() == 1) return true;
            return false;
        }
        // 255只需要三个字符就能表示(所以这里并不需要直接使用stoll这种将string转换成为long long int的转换工具)
        if(s.size() > 3) return false;
        int i = stoi(s);
        if(i<0 || i>255)
            return false;
        return true;
    }

    void backtracking(string& s, int start_index)
    {
        if(path.size() > 4)
            return;

        if(start_index >= s.size() && path.size() == 4)
        {
            string temp = {};
            for(auto& i : path)
                temp = temp + i + '.';
            temp.pop_back();
            res.push_back(temp);
            return;
        }

        // 分割字符串(当然这里也可以实现一些提前截断的操作实现整体的退出工作)
        for(int i = 0; (start_index+i)<s.size(); i++)
        {
            auto str = s.substr(start_index, i+1);
            if(isValid(str))
            {
                path.push_back(str);
                backtracking(s,start_index+i+1);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) return {};
        backtracking(s,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution93;
int main() {
    Solution solution = Solution();
    solution.restoreIpAddresses("101023");
    for(auto i : solution.res)
    {
        cout << i << endl;
    }
    return 0;
}

