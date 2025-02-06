//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution541{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void trans(string & s, int left, int right)
    {
        while(left < right)
        {
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            --right;
            ++left;
        }
    }

    string reverseStr(string s, int k)
    {
        if(s.empty()) return s;
        int left = 0;
        int right = k - 1; // k个字符

        while(right < s.size())
        {
            trans(s, left, right);
            left = left + 2*k;
            right = right + 2*k;
        }

        // 最后剩余的字符数量判断是否大于k
        if(left < s.size() - 1) trans(s, left, s.size()-1);
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution541;
int main() {
    Solution solution = Solution();

    return 0;
}

