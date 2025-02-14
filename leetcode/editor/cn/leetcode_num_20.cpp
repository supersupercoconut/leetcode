#include "../../../stdc.h"
using namespace std;

namespace solution20{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> res;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                res.push(s[i]);

            else if(s[i] == ')')
            {
                if(res.empty() || res.top() != '(') return false;
                res.pop();
            }
            else if(s[i] == '}')
            {
                if(res.empty() || res.top() != '{') return false;
                res.pop();
            }
            else if(s[i] == ']')
            {
                if(res.empty() || res.top() != '[') return false;
                res.pop();
            }

            ++i;
        }

        if(res.empty()) return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution20;
int main() {
    Solution solution = Solution();

    return 0;
}
