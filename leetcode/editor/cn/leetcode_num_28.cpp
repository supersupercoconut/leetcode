#include "../../../stdc.h"
using namespace std;

namespace solution28{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

  // 基于s字符串计算 next数组
  void computeNext(std::vector<int>& next, string & s)
  {
    next.resize(s.size());
    int i = 0;
    next[0] = 0;
    while(i < s.size())
    {
      if(i != 0)
      {
        int tmp = next[i-1];
        while(tmp > 0 && s[i] != s[tmp])
          tmp = next[tmp-1];

        if(s[i] == s[tmp]) next[i] = tmp+1;
        else
          next[i] = 0;
      }
      ++i;
    }
  }

  int strStr(string haystack, string needle)
  {
        // note 这里是需要利用KMP方法进行实现的 - 需要手动构建一个next数组 | 本问题的难点还是在于手动构建这个next数组，并且使用这个数组去实现匹配
        vector<int> next;
        computeNext(next,needle);

        for(auto i : next)
          cout << i << " ";

        // 匹配
        int left = 0, right = 0;
        while(left < haystack.size())
        {
            if(haystack[left] == needle[right]) ++right;
            else
            {
                while(right > 0 && haystack[left] != needle[right])
                {
                    right = next[right-1];
                }
                if(haystack[left] == needle[right]) right = right + 1;
                else
                    right = 0;
            }
          if(right >= needle.size()) return left - needle.size() + 1;
          ++left;
        }
        return -1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution28;
int main() {
    Solution solution = Solution();

    return 0;
}
