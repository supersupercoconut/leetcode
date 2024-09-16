#include "../../../stdc.h"
using namespace std;

namespace solution94{
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

void traversal(TreeNode* root , vector<int>& res )
{
    // 递归的终止条件 - 无论怎么遍历都是靠这一步判断是不是需要停止
    if(root == nullptr) return;
    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        traversal(root,res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution94;
int main() {
    Solution solution = Solution();

    return 0;
}
