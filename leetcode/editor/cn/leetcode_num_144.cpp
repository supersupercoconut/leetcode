#include "../../../stdc.h"

using namespace std;


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

// 在这里使用stack实现迭代遍历，仍然是一种深度优先的遍历方式，不过使用stack可以很好的将之前的数据保存下来(因为TreeNode中不能指向其父结点)
void stack_traversal(TreeNode* root, vector<int>& res)
{
    if(root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode*  temp = st.top();
        res.push_back(temp->val);
        st.pop();
        // 两者可以同时执行
        if(temp->right != nullptr)
            st.push(temp->right);
        if(temp->left != nullptr)
            st.push(temp->left);
        continue;
    }
}


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        /*** 递归方法 —— 确定形参以及终止条件  ***/
//        vector<int> res={};
//        traversal(root, res);
//        return res;

        /*** 迭代方法 ***/
        vector<int> res={};
        stack_traversal(root, res);
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
