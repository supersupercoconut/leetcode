//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution404{
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

// 改变之前的逻辑, 提前一个节点判断其是不是左叶子节点
int traversal(TreeNode* treeNode)
{
    int res = 0;
    if(treeNode->left != nullptr && treeNode->left->left == nullptr && treeNode->left->right == nullptr)
        res += treeNode->left->val;

    int left = 0;
    int right = 0;
    if(treeNode->left != nullptr)
        left = traversal(treeNode->left);
    if(treeNode->right != nullptr)
        right = traversal(treeNode->right);

    res = res + left + right;
    return res;

}

/*** 层次遍历(每一个左侧子树存放的时候,都去单独判断一下即可) ***/
int level_traversal(TreeNode* treeNode)
{
    queue<TreeNode*> q;
    q.push(treeNode);
    int size = 1;
    int res = 0;
    while(!q.empty()) {
        size = q.size();
        while (size > 0) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left) {
                if (temp->left->left == nullptr && temp->left->right == nullptr)
                    res += temp->left->val;
                q.push(temp->left);
            }
            if (temp->right)
                q.push(temp->right);
            size--;
        }
    }
    return res;

}


// 判断左叶子节点 - 需要先找到叶子节点，再去确定其是在左子树的位置上
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(root == nullptr) return 0;
//        return traversal(root);
        return level_traversal(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution404;
int main() {
    Solution solution = Solution();

    return 0;
}

