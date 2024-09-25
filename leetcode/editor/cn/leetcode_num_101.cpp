//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution101{
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

/* 实现后序遍历
 * 1. 输入两个子树
 * 2. 一个比较左侧数据，一个比较右侧数据
 * */
bool traversal(TreeNode* left, TreeNode* right)
{
    if(left == nullptr && right == nullptr) return true;
    else if(left != nullptr && right == nullptr) return false;
    else if(left == nullptr && right != nullptr) return false;
    else if(left->val != right->val) return false;
    // 剩余部分就是left与right的val是相等的
    else
    {
        // 这里不仅要判断当前的left与right的val是不是相等，是要去判断整个左右子树是不是相等的
        bool outside = traversal(left->left, right->right);
        if(!outside) return false;
        bool inside = traversal(left->right,right->left);
        if(!inside) return false;
        return true;
    }

}

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root == nullptr) return false;
        bool flag = traversal(root->left, root->right);
        // 改造后的后序遍历，分析左右子树之后再去比较判断
        return flag;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution101;
int main() {
    Solution solution = Solution();

    return 0;
}