//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution222{
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

/***
 * 1. 利用完全二叉树的性质 : 可以通过一直遍历左侧子树以及右侧子树快速计算节点数量
 * 2. 算法的整体思路我个人感觉是一种后序遍历，即处理完左右子树的数据之后再分析，这与常规二叉树中的后序遍历逻辑是一样的
 * 本题的难点在于:
 *      (1)利用二叉树的性质, 沿左侧以及右侧遍历可以快速判断节点数量
 *      (2)如果不能快速判断，剩余逻辑转换为递归将剩余部分不断按照左右子树进行切割(并且判断是否是满二叉树的方法一直使用，其时间复杂度也就二叉树的深度，相比于遍历整个二叉树不值一提)
 *
 * ***/
int traversal(TreeNode* treeNode)
{
    // 本函数不使用两个TreeNode指针而是使用一个指针的原因在于其返回值 | 节点对应返回的数据应该是左子树的节点+右子树的节点+1, 所有递归的逻辑就是先计算左子树节点, 后计算右子树节点
    if(treeNode->left == nullptr && treeNode->right == nullptr)
        return 1;
    int left = 1;
    int right = 1;
    TreeNode* left_ptr = treeNode->left;
    TreeNode* right_ptr = treeNode->right;

    while(left_ptr != nullptr)
    {
        left_ptr = left_ptr->left;
        left++;
    }
    while(right_ptr != nullptr)
    {
        right_ptr = right_ptr->right;
        right++;
    }
    // 满二叉树
    int res = 0;
    int left_num = 0;
    int right_num = 0;

    if(left == right)
        res = (1<<left)-1;
    else
    {
        // 递归过程中对一直不是满二叉树的部分, 其会一直找到叶子节点对应的部分进行处理, 这样计算节点可以用一套逻辑进行处理
        if(treeNode->left != nullptr) left_num = traversal(treeNode->left);
        if(treeNode->right != nullptr) right_num = traversal(treeNode->right);
        res = left_num+right_num+1;
    }
    return res;
}

class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return traversal(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution222;
int main() {
    Solution solution = Solution();

    return 0;
}

