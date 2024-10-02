//import universal *.h
#include "../../../stdc.h"

using namespace std;


namespace solution113{
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

void traversal(TreeNode* treeNode, vector<int>& path, vector<vector<int>>& res_vector, int targetSum)
{
    path.push_back(treeNode->val);
    // 找到叶子节点
    if(treeNode->left == nullptr && treeNode->right == nullptr)
    {
        int res = 0;
        for(auto i : path)
            res += i;
        if(res == targetSum)
            res_vector.push_back(path);
    }

    if(treeNode->left != nullptr)
    {
        traversal(treeNode->left, path, res_vector, targetSum);
        path.pop_back();
    }

    if(treeNode->right != nullptr)
    {
        traversal(treeNode->right, path, res_vector, targetSum);
        path.pop_back();
    }

}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> path;
        traversal(root, path, res, targetSum);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution113;
int main() {
    Solution solution = Solution();

    return 0;
}

