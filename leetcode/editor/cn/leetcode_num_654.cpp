//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution654{
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

int findMax(vector<int>& nums)
{
    int max = nums[0];
    for(auto i : nums)
        max = i > max ? i : max;
    return max;
}

/*** 方法1: 首先处理中间节点，按照数组划分的方式划分左右子树 ***/
TreeNode* traversal(vector<int>& nums)
{
    if(nums.empty()) return nullptr;
    // 查找最大值
    int in_val = findMax(nums);
    TreeNode* in_node = new TreeNode(in_val);
    if(nums.size() == 1)
        return in_node;

    vector<int> left_array = {};
    vector<int> right_array = {};

    int i = 0;
    for(; nums[i] != in_val; ++i)
        left_array.push_back(nums[i]);
    ++i;
    for(; i < nums.size(); ++i)
        right_array.push_back(nums[i]);

    TreeNode* left = traversal(left_array);
    TreeNode* right = traversal(right_array);

    in_node->left = left;
    in_node->right = right;
    return in_node;
}

/*** 方法2: 不另外划分子数组而是直接在原始数组上进行操作(减少了新建数组带来的效率损失) ***/




class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.empty()) return nullptr;
        return traversal(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution654;
int main() {
    Solution solution = Solution();

    return 0;
}

