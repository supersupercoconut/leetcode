//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution617{
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

TreeNode* merge(TreeNode* ptr_1, TreeNode* ptr_2)
{
    // 之前的判断逻辑比较复杂 —— 实际上是可以简化的
//    if(ptr_1 == nullptr && ptr_2 == nullptr)
//        return nullptr;
//    else if(ptr_1 == nullptr && ptr_2 != nullptr)
//        return ptr_2;
//    else if(ptr_1 != nullptr && ptr_2 == nullptr)
//        return ptr_1;

    // 简化之后更简便
    if(ptr_1 == nullptr) return ptr_2;
    if(ptr_2 == nullptr) return ptr_1;
    else
    {
        int new_val = ptr_1->val + ptr_2->val;
        // TODO 这里可以不新建二叉树, 直接使用其中一个树进行修改
        TreeNode* new_node = new TreeNode(new_val);
        // 给定左右子树
        TreeNode* left = merge(ptr_1->left, ptr_2->left);
        TreeNode* right = merge(ptr_1->right, ptr_2->right);
        new_node->left = left;
        new_node->right = right;
        return new_node;
    }

}



class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        // 函数自带异常状态判断功能
        return merge(root1, root2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution617;
int main() {
    Solution solution = Solution();

    return 0;
}

