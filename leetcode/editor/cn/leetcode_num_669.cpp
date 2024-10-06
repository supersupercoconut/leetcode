//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution669{
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
    // note 本题还是很好的，至少我没有找到合适的逻辑去处理这部分(随想录中给出的解法不错, 正常节点找两边, 不满足分别找左右)
    // 这里需要返回值 —— 对于修改结构的部分, 直接获取修改之后的结果 | 对于未修改部分，直接返回node本身 | node自身的left与right可以直接接受来自左右子树的修改结果
    TreeNode* modify_tree(TreeNode* node, int low, int high)
    {
        // 相当于前序遍历
        if(node == nullptr) return nullptr;

        if(node->val > high)
        {
            // 首先right指向的部分一定是存在的，所以不需要考虑其被释放 | 而且这部分不会
            TreeNode* left = modify_tree(node->left, low, high);
            return left;
        }

        if(node->val < low)
        {
            TreeNode* right = modify_tree(node->right,low,high);
            return right;
        }

        // node取值在low与high之间, 即考虑剩余部分 (就算node的值在low以及high的时候,后续遍历也会逐渐删除这部分 —— 虽然可以提前截断,但是不写也是可以的)
        node->left = modify_tree(node->left,low,high);
        node->right = modify_tree(node->right,low,high);
        return node;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(root == nullptr) return root;
        return modify_tree(root,low,high);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution669;
int main() {
    Solution solution = Solution();

    return 0;
}

