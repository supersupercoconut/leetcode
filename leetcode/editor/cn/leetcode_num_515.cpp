//import universal *.h
#include "../../../stdc.h"
using namespace std;


namespace solution515{
    //leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
        if(root == nullptr) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            // 0x80000000 直接使用了32位int类型中的最小值 | 0xffffffff 才是对应的负数最大值-1
            int MAX_MUM = 0x80000000;
            int size = q.size();

            while(size > 0)
            {
                TreeNode* temp = q.front();
                q.pop();
                MAX_MUM = temp->val > MAX_MUM ? temp->val : MAX_MUM;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                size--;
            }
            res.push_back(MAX_MUM);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution515;
int main() {
    Solution solution = Solution();

    return 0;
}
