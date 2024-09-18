#include "../../../stdc.h"
using namespace std;

namespace solution94{
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


void traversal(TreeNode* root , vector<int>& res )
{
    // 递归的终止条件 - 无论怎么遍历都是靠这一步判断是不是需要停止
    if(root == nullptr) return;
    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);
}

// 中序遍历比其他两种困难的部分在于中间点的处理上,这里需要额外加入指针来进行处理,方便对中间点的回滚(stack中保留的就是中间点)
void stack_traversal(TreeNode* root , vector<int>& res )
{
    if(root == nullptr) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* cur = root->left;

    // note 如果在这里不加入cur是否为空的判断，整个程序只会去分析左子树并不会去分析右子树(这里一定要注意!!)
    while( cur != nullptr || !s.empty()){
      // 说明当前节点没有左子树,那么可以直接将数据放入res并且查询右子树
        if(cur == nullptr)
        {
            cur = s.top();
            res.push_back(cur->val);
            s.pop();
            cur = cur->right;
        }
        else
        {
            s.push(cur);
            cur = cur->left;
        }
    }
}

/*
 * 后续在代码随想录上针对遍历实现前中后三种遍历方法代码不能复用的情况又做了更改
 * 1. 解决了访问的结点不一定是需要处理结点的情况
 * 2. 在访问中间结点的时候，加入了NULL. 针对stack中的元素是否为NULL分策略进行读取(就是不知道这种策略是不是在其他情况也能使用)
 * */


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        // traversal(root,res);
        stack_traversal(root,res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution94;
int main() {
    Solution solution = Solution();

    return 0;
}
