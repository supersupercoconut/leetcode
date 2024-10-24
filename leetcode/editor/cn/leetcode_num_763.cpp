#include "../../../stdc.h"

using namespace std;
namespace solution763{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 一种字母最多出现在一个片段中 | 对片段的数量没有要求, 只需要符合条件即可
    void traversal(string& s, unordered_map<char, int>& hash_map)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(hash_map.find(s[i]) != hash_map.end())
                hash_map[s[i]] = i; // 因为是往后遍历,后面获取的到i一定是比前面的i要靠前的
            else
                hash_map.insert(pair<char,int>(s[i],i));
        }
    }

    // 整体在O(n)中完成处理, hash表中只需要执行出来之后, 遍历整个字符串找分割点
    vector<int> partitionLabels(string s)
    {
        // 因为需要遍历出整个字符串中每一种字符出现的最远区域, 这种遍历耗费时间只能是O(n)
        vector<int> res = {};
        unordered_map<char, int> hash_map = {};
        traversal(s, hash_map);

        for(auto i : hash_map)
        {
            cout << i.first << " " << i.second <<endl;
        }

        int count = 0;
        int res_num = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            count = hash_map[s[i]] > count ? hash_map[s[i]] : count;
            if(i == count)
            {
                count = 0;
                res.push_back(res_num);
                res_num = 0;
            }
            res_num++;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution763;
int main() {
    Solution solution = Solution();

    return 0;
}
