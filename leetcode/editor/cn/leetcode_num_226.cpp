//import universal *.h
#include "../../../stdc.h"

using namespace std;



namespace solution226{
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

//void traverse(TreeNode* treeNode)
//{
//    // 对于中心节点 互换左右(这里无需判断左右是不是空);
//    TreeNode* temp = treeNode->left;
//    treeNode->left = treeNode->right;
//    treeNode->right = temp;
//    if(treeNode->left) traverse(treeNode->left);
//    if(treeNode->right) traverse(treeNode->right);
//
//}




    void traverse(TreeNode* root)
    {
        if(root == nullptr) return;
        swap(root->left, root->right);
        traverse(root->left);
        traverse(root->right);
    }

class Solution {
public:
    // 可以使用迭代或者是递归来实现翻转过程，即对除去叶子节点之外的其他节点进行左右字数的翻转 (前序遍历使用比较简单)
    TreeNode* invertTree(TreeNode* root)
    {
        if(root == nullptr) return nullptr;
        traverse(root);
        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution226;
int main() {
    Solution solution = Solution();

    return 0;
}