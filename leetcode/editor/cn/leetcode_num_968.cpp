#include "../../../stdc.h"
using namespace std;

namespace solution968{
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

    int res = 0;

    // 按照左右中的顺序进行遍历
    // 0: 无覆盖 | 1: 监视节点 | 2: 被覆盖
    int traversal(TreeNode* node)
    {
        if(node == nullptr) return 2;
        int left = traversal(node->left);
        int right = traversal(node->right);

        if (left == 2 && right == 2) return 0;

        if (left == 0 || right == 0) {
            res++;
            return 1;
        }

        if (left == 1 || right == 1) return 2;

        return -1;

    }

    int minCameraCover(TreeNode* root)
    {
        if(root == nullptr) return 0;
        // 针对单一叶子节点
        if(root->left == nullptr && root->right == nullptr) return 1;
        if(traversal(root) == 0)
            res++;
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution968;
int main() {
    Solution solution = Solution();

    return 0;
}
