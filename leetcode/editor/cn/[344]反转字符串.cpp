#include "../../../stdc.h"

using namespace std;

namespace solution344{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 很简单的反转
    void reverseString(vector<char>& s)
    {
        int left = 0;
        int right = s.size()-1;
        while(left<right)
            swap(s[left++],s[right--]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution344;
int main() {
    Solution solution = Solution();

    return 0;
}
