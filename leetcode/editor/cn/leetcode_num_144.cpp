#include "../../../stdc.h"

using namespace std;


//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
//
// 
// 输入：root = [1,null,2,3] 
// 
//
// 输出：[1,2,3] 
//
// 解释： 
//
// 
//
// 示例 2： 
//
// 
// 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9] 
// 
//
// 输出：[1,2,4,5,6,7,3,8,9] 
//
// 解释： 
//
// 
//
// 示例 3： 
//
// 
// 输入：root = [] 
// 
//
// 输出：[] 
//
// 示例 4： 
//
// 
// 输入：root = [1] 
// 
//
// 输出：[1] 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1275 👎 0


namespace solution144{
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
void traversal(TreeNode* root, vector<int>& res)
{
    // 前序遍历 先处理根结点
    if(root == nullptr) return;
    res.push_back(root->val);
    // 递归的层数会逐渐变大，在这个变大的过程中, 都是先处理左子树，再处理右子树
    traversal(root->left, res);
    traversal(root->right, res);
}

class Solution {
public:
    /*** 递归方法 —— 确定形参以及终止条件  ***/
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res={};
        traversal(root, res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution144;
int main() {
    Solution solution = Solution();

    return 0;
}
