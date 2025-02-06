//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution383{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> search;
        for(int i = 0; i < magazine.length(); i++)
        {
            if(search.find(magazine[i]) != search.end())
              search[magazine[i]]++;
            else
              search[magazine[i]] = 1;
        }

        for(int i = 0; i < ransomNote.length(); i++)
        {
            if(search.find(ransomNote[i]) != search.end())
            {
               search[ransomNote[i]]--;
               if(search[ransomNote[i]] < 0) return false;
            }
          else
               return false;
        }
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

