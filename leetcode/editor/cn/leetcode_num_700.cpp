//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution700{
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

TreeNode* search(TreeNode* treeNode, int val)
{
    if(treeNode->val == val)
        return treeNode;
    if(treeNode->left == nullptr && treeNode->right == nullptr)
        return nullptr;

    // 即不相等又不是左右叶子节点(不考虑二叉树中的值相等) | 这里left、right也是局部变量，不会自动给定nullptr的值
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    // 在这里加入判断条件保证输入的treeNode不会为空
    if(treeNode->val > val && treeNode->left != nullptr)
        left = search(treeNode->left,val);
    if(treeNode->val < val && treeNode->right != nullptr)
        right = search(treeNode->right,val);

    if(left == nullptr) return right;
    if(right == nullptr) return left;
    return nullptr;
}

class Solution {
public:
    // 针对的是二叉搜索树的搜索, 可以利用其二叉树数值的排列顺序进行处理
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root == nullptr) return nullptr;
        return search(root, val);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution700;
int main() {
    Solution solution = Solution();

    return 0;
}

