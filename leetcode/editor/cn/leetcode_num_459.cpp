#include "../../../stdc.h"
using namespace std;

namespace solution459{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void computeNext(string& s, vector<int>& next)
    {
        next.resize(s.size());
        next[0] = 0;
        int i = 1;
        while(i < s.size())
        {
            int tmp = next[i-1];

            while(tmp > 0 && s[tmp] != s[i])
              tmp = next[tmp-1];

            if(s[i] == s[tmp]) next[i] = tmp + 1;
            else
                next[i] = 0;

            ++i;
        }
    }


    bool repeatedSubstringPattern(string s)
    {
        // note 目前我假设这里是通过next前缀表来判断整体逻辑的(可以按照两相同字符串拼接，中心位置会剩下一个与原始字符串相同的字符， 利用next数组整体的时间复杂度也就是O(m+n))
        if(s.size() == 0) return false;
        vector<int> next;
        computeNext(s, next);

        // 分析重复的字符串
        string s2 = s + s;
        s2 = s2.substr(1, s2.size()-2);
		cout << s2 << endl;
        int left = 0;
        int right = 0;

        while(left < s2.size())
        {
			while(right > 0 && s2[left] != s[right])
                right = next[right-1];

            if(s2[left] == s[right]) right++;
            else
            	right = 0;

            if(right >= s.size()) return true;

         	++left;
        }
		return false;


        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution459;
int main() {
    Solution solution = Solution();

    return 0;
}
