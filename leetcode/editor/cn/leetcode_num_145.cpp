#include "../../../stdc.h"

using namespace std;

namespace solution145{
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

void traversal(TreeNode* root , vector<int>& res)
{
    if(root == nullptr) return;
    traversal(root->left, res);
    traversal(root->right, res);
    res.push_back(root->val);
}

void stack_traversal(TreeNode* root , vector<int>& res)
{

}

class Solution {
public:
    // 后序遍历，按照左右中的顺序遍历
    vector<int> postorderTraversal(TreeNode* root)
    {
//        if(root == nullptr) return {};
//        vector<int> res = {};
//        traversal(root, res);
//        return res;

        /*** 迭代遍历 ***/
        vector<int> res = {};
        stack_traversal(root, res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution145;
int main() {
    Solution solution = Solution();

    return 0;
}
