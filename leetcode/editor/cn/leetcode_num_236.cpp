//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution236{
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

TreeNode* traversal(TreeNode* node, TreeNode* p, TreeNode* q)
{
    // 貌似将判断是不是空的条件放在这里的话，整体代码逻辑是最简单的
    if(node == p || node == q || node == nullptr)
        return node;
    // 利用后序遍历进行查找 | 无论是left查找到还是right查找到p或者q的其中一个就行 亦或者是中间节点是p/q其中一个
        // 这里进入之前判断下 node->left与node->right 是否为nullptr也是ok的
    TreeNode* left = traversal(node->left,p,q);
    TreeNode* right = traversal(node->right,p,q);

    // note 这里判断很简单的原因主要是源于进入函数关于node的判断, 这里直接将node可能是p,q值的可鞥行包含了(如果node是q，并且其它方向都没有返回p值，但是p一定在二叉树中，所以node一定是最深的祖先)
    if(left != nullptr && right != nullptr)
        return node;
    else if(left != nullptr && right == nullptr)
        return left;
    else if(left == nullptr && right != nullptr)
        return right;
    else
        return nullptr;
}

class Solution {
public:
    // 给定两个节点，其对应的公共节点的深度要大(深度越大就是越往下深度越大)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
        return traversal(root, p, q);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution236;
int main() {
    Solution solution = Solution();

    return 0;
}

