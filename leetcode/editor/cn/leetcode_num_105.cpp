//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution105{
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

// 解决类似问题的方法为: 从前序/后序数组中找到中间节点, 然后从中序数组中切割出左右子树，根据左右子树的节点数量就能分割前序/后序数组中的节点分割，以此类推进入递归就能实现整体逻辑
TreeNode* traversal(vector<int>& pre_array, vector<int>& in_array)
{
    if(pre_array.empty() || in_array.empty() )
        return nullptr;

    int in_val = pre_array[0];
    TreeNode* in_node = new TreeNode(in_val);
    if(pre_array.size() == 1)
        return in_node;

    vector<int> in_left;
    vector<int> in_right;
    // 中序数组分割
    int i = 0;
    for(; in_array[i] != in_val; ++i)
        in_left.push_back(in_array[i]);
    ++i;
    for(; i < in_array.size(); ++i)
        in_right.push_back(in_array[i]);

    // 后序数组分割
    vector<int> pre_left;
    vector<int> pre_right;
    int j = 0;
    for(; j < in_left.size(); ++j)
        pre_left.push_back(pre_array[j+1]);
    for(; j < pre_array.size()-1; ++j)
        pre_right.push_back(pre_array[j+1]);

    TreeNode* left = traversal(pre_left,in_left);
    TreeNode* right = traversal(pre_right, in_right);

    in_node->left = left;
    in_node->right = right;
    return in_node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        return traversal(preorder, inorder);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution105;
int main() {
    Solution solution = Solution();

    return 0;
}

