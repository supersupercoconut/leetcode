#include "../../../stdc.h"
using namespace std;

namespace solution337{
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
    // note 基于二叉树结构分析整个逻辑 —— 但是没有想清楚dp[]数组对应的含义是什么
    int rob(TreeNode* root)
    {
        // 这里并没有显式表示出整个dp数组，而是将每一个节点都分析成了偷/不偷两种状态
        auto temp = robTree(root);
        return max(temp[0], temp[1]);
    }

    vector<int> robTree(TreeNode* node)
    {
        // 返回的vector中第一个元素表示考虑不使用当前节点，第二个元素表示使用当前节点
        if(node == nullptr) return {0,0};
        auto left = robTree(node->left);
        auto right = robTree(node->right);

        // note 关于不偷当前节点的情况，这里有一个很严重的错误...这里对于左右节点未必要使用，所以需要比较左右节点需要不需要使用
        int a = max(left[0], left[1]) + max(right[0], right[1]);
        int b = left[0] + right[0] + node->val;
        return {a,b};
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution337;
int main() {
    Solution solution = Solution();

    return 0;
}
