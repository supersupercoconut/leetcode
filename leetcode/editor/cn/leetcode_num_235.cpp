//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution235{
    //leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 将236的普通二叉树转换成了235中的二叉搜索树
// left与right就决定了p、q中大小顺序, 然后就可以通过中心节点的顺序判断要不要返回, 以及要下一个节点要往哪里走(左/右)
TreeNode* traversal(TreeNode* node, TreeNode* left, TreeNode* right)
{
    // note 本问题最有技巧的部分在于第一次在p,q区间中的node,一定就是最深的(在区间中间，那么p,q一定是分解在两个子树中,这时候无论node往左右哪一个方向移动，其不会是最深)
    if(node->val >= left->val && node->val <= right->val)
        return node;

    TreeNode* left_res = nullptr;
    TreeNode* right_res = nullptr;
    // 由于是二叉搜索树，其往一个方向遍历就OK了，不需要往两个方向移动
    if(node->left != nullptr && node->val > right->val)
        left_res = traversal(node->left,left,right);
    if(node->right != nullptr && node->val < left->val)
        right_res = traversal(node->right,left,right);

    // 由于整个二叉搜索树的逻辑, left与right至少会有一个是nullptr, 所以这里直接判断即可
    if(left_res == nullptr) return right_res;
    if(right_res == nullptr) return left_res;
    return nullptr;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(p->val > q->val) return traversal(root, q,p);
        else
            return traversal(root,p,q);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution235;
int main() {
    Solution solution = Solution();

    return 0;
}

