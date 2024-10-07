//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution538{
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

    /*** 1.个人方法: 比较简单的实现(先遍历完整个二叉树,然后中序遍历不断给二叉树赋值) ***/
    int sum = 0;
    // 遍历树,将所有的值都计算一下
    int countTree(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int res = 0;
        res += countTree(root->left);
        res += root->val;
        res += countTree(root->right);
        return res;
    }

    // 不需要返回值是因为不需要改变树的逻辑
    void modify_tree(TreeNode* node)
    {
        if(node == nullptr) return;
        modify_tree(node->left);

        int temp = node->val;
        node->val = sum;
        sum = sum - temp;

        modify_tree(node->right);

    }

    /*** 2. 随想录中的方法: 反中序遍历(这里只需要将二叉树遍历一遍,然后不断累加就好) ***/
    int pre = 0;
    void traversal(TreeNode* node)
    {
        // 右中左遍历
        if(node == nullptr) return;
        traversal(node->right);
        // 中序遍历
        node->val += pre;
        pre = node->val;
        traversal(node->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;

        /* 个人思路 */
//        sum = countTree(root);
//        modify_tree(root);
//        return root;

        /* 随想录 */
        traversal(root);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution538;
int main() {
    Solution solution = Solution();

    return 0;
}

