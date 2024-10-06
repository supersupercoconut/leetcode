//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution450{
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
    /** 个人思路(比较复杂): 先利用二叉搜索树找key值，判断是否能找到这个key -> 在找到这个key值的基础上，去重构对应node上面的二叉树,最后返回给pre的左/右分支，最终形成一个完成的二叉树 **/
    // 因为find_value函数会找到当前节点, pre需要确定最后重构完整体逻辑之后,剩余部分需要如何添加到整个二叉树上
    TreeNode* pre = nullptr;
    TreeNode* find_value(TreeNode* node, int key)
    {
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if(node->val == key)
            return node;

        // pre需要在调用函数的前面进行判断, 这样进入left或者right分支的时候，这里对应的就是中间节点(整体逻辑属于前序遍历)
        pre = node;
        if(node->val > key && node->left != nullptr)
            left = find_value(node->left,key);
        if(node->val < key && node->right != nullptr)
            right = find_value(node->right,key);

        // 不可能出现 left与right同时不为nullptr
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return nullptr;
    }

    // 需要删除的是当前这个节点(需要讨论左右是不是为nullptr的情况)
    TreeNode* modify_tree(TreeNode* node)
    {
        if(node->right != nullptr)
        {
            if(node->left == nullptr) return node->right;
            else
            {
                TreeNode* temp = node->right;
                while(temp->left)
                    temp = temp->left;
                temp->left = node->left;
                return node->right;
            }
        }
        else
            return node->left;
    }

    /** 代码随想录中的方法是在同一个函数中完成了查询节点并且重构二叉树
     *  1. 函数返回值TreeNode 这样可以方便上一层节点接受重构之后的二叉树(而且对于中间一些不为空也不等于key的节点，默认直接返回node本身)
     *  2. 遍历顺序为中序遍历, 与我自己的方法类似
     * **/

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == nullptr) return root;
        TreeNode* temp = find_value(root,key);
        if(temp == nullptr)
            return root;
        else
        {
            // 针对pre上来就碰到这个元素的情况
            if(pre == nullptr)
                return modify_tree(temp);
            if(pre->left != nullptr && pre->left->val == key)
                pre->left = modify_tree(temp);
            if(pre->right != nullptr && pre->right->val == key)
                pre->right = modify_tree(temp);
            return root;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution450;
int main() {
    Solution solution = Solution();

    return 0;
}

