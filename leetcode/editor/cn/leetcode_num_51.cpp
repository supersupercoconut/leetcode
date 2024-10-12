//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution51{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /** 1. 个人方法 —— 这也相当于是一个穷举问题, 只不过将穷举问题换成了二维的, 多叉树中的每一层都是n, 最后相当于是一个n*n的遍历过程
     *  本问题在于 回溯上困难，并且判断防止位置是否合理也困难
     *  (1) 每一层选择Q的位置, 生成一个Q的位置字串 (2) 判断下一层字符串能否通过判断,
     *  (3) 需要考虑在有些条件下n皇后问题是无解的 —— 但其实不需要多余设计退出条件，找不到就返回空即可
     * **/
     // note 本问题最大的缺陷就是在定义变量的时候不清晰！！！导致debug的时候都是在解决变量的误用
    vector<vector<string>> res = {};  // res代表的是不同解法
    vector<string> path = {};
    int depth = 0;
    string level = {};
    // 利用当前字符串以及 之前字符串当前大小n判断
    bool isValid(string& s)
    {
        if(path.empty()) return true;
        int now_size = path.size();                 // 得到当前行对应的位置
        vector<int> now_level = {};                 // 记录当前行不应该出现什么元素
        now_level.resize(path[0].size());
        now_level.assign(path[0].size(),0);

        // 分析当前行不应该出现Q的位置
        for(int i = 0; i < path.size(); i++)
        {
            for(int j = 0; j < now_level.size(); ++j)
            {
                if(path[i][j] == 'Q')
                {
                    now_level[j] = 1;
                    if(j - (now_size - i) >=0) now_level[j - (now_size - i)] = 1;
                    if(j + (now_size - i) < now_level.size()) now_level[j + now_size - i] = 1;
                }
            }
        }

        for(int i = 0; i < now_level.size(); ++i)
        {
            if(s[i] == 'Q' && now_level[i] != 1) return true;
        }
        return false;
    }

    // n对应实际大小
    void backtracking(int n)
    {
        // 由于可能出现无解的情况
        if(depth == n) {
            res.push_back(path);
            return;
        }
        // i 为 Q位置  j为其余部分的位置
        for(int i = 0; i < n; ++i)
        {
            level = {};
            // 创建当前行的取值
            for(int j = 0; j < n ;++j)
            {
                if(j == i)
                    level += 'Q';
                else
                    level += '.';
            }
            // 判断当前行的Q位置是否符合要求
            if(isValid(level))
            {
                path.push_back(level);
                depth++;
                backtracking(n);
                depth--;
                path.pop_back();
            }
            else continue;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        backtracking(n);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution51;
int main() {
    Solution solution = Solution();
    solution.solveNQueens(4);
    return 0;
}

