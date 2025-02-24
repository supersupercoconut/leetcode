#include "../../../stdc.h"

using namespace std;

namespace solution145{
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

void traversal(TreeNode* root , vector<int>& res)
{
    if(root == nullptr) return;
    traversal(root->left, res);
    traversal(root->right, res);
    res.push_back(root->val);
}

void stack_traversal(TreeNode* root , vector<int>& res)
{
    if(root == nullptr) return;
    stack<TreeNode*> s;
    s.push(root);
    /* 后序遍历 —— 按照左右中的顺序处理 | 有一种比较tricky的方法, 不需要解决访问顺序与读取顺序不一致的问题
     *     只需要将读取方式更换中右左的处理方法, 最后将result数组反转, 就可以解决如下问题，并且整理的流程还与前序遍历类似
     * */
    while(!s.empty())
    {
        TreeNode* temp = s.top();
        s.pop();
        res.push_back(temp->val);
        // 注意stack中的顺序按照 "中右左"的方法, 需要确定入栈顺序 先入栈后处理!!!
        if(temp->left) s.push(temp->left);
        if(temp->right) s.push(temp->right);
    }
    reverse(res.begin(), res.end());
}

void myTraversal(TreeNode* root, vector<int>& res)
{
    if(root == nullptr) return;
    stack<TreeNode*> s;
    unordered_set<TreeNode*> used;
    s.push(root);
    while(!s.empty())
    {
        auto tmp = s.top();
        s.pop();

        if(used.find(tmp) == used.end()) used.insert(tmp);
        else
        {
            res.push_back(tmp->val);
            continue;
        }

        s.push(tmp);
        if(tmp->right) s.push(tmp->right);
        if(tmp->left) s.push(tmp->left);

    }
}



class Solution {
public:
    // 后序遍历，按照左右中的顺序遍历
    vector<int> postorderTraversal(TreeNode* root)
    {
//        if(root == nullptr) return {};
//        vector<int> res = {};
//        traversal(root, res);
//        return res;

        /*** 迭代遍历 ***/
        vector<int> res = {};
//        stack_traversal(root, res);
        myTraversal(root, res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution145;
int main() {
    Solution solution = Solution();

    return 0;
}
