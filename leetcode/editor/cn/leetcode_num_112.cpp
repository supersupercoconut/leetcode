//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution112{
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

// note 在traversal()函数中res一开始没有直接赋值为0, 导致计算上一直有问题

bool traversal(TreeNode* treeNode, vector<int>& path, int targetSum)
{
    path.push_back(treeNode->val);
    // 找到叶子节点
    if(treeNode->left == nullptr && treeNode->right == nullptr)
    {
        int res = 0;
        for(auto i : path)
            res += i;
        if(res == targetSum)
            return true;
        else
            return false;
    }

    if(treeNode->left != nullptr)
    {
        if(traversal(treeNode->left, path, targetSum))
            return true;
        path.pop_back();
    }

    if(treeNode->right != nullptr)
    {
        if(traversal(treeNode->right, path, targetSum))
            return true;
        path.pop_back();
    }

    return false;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr) return false;
        vector<int> path;
        return traversal(root, path, targetSum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution112;
int main() {
    Solution solution = Solution();

    return 0;
}

