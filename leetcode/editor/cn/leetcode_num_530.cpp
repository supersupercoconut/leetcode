//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution530{
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
    /*** 这里使用的是一种双指针遍历的方法, 将上一次的遍历到的部分保存到pre中(应该比直接使用node->right - node的值方便一些，那种方法还得判断node->right是不是nullptr) ***/
    TreeNode* pre = nullptr;
    // int 返回节点值
    int res = 0x7fffffff;
    void traversal(TreeNode* node)
    {
        if(node->left != nullptr)
            traversal(node->left);

        if(pre != nullptr)
            res = (node->val - pre->val) > res ? res : (node->val - pre->val);
        pre = node;

        if(node->right != nullptr)
            traversal(node->right);
    }

    // 二叉搜索树中的最小差值 —— 即在遍历二叉树的基础上,直接找中序遍历顺序上的两个节点之间的最小差值
    int getMinimumDifference(TreeNode* root)
    {
        if(root == nullptr) return 0;
        traversal(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution530;
int main() {
    Solution solution = Solution();

    return 0;
}

