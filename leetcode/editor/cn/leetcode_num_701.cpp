//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution701{
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

    void traversal(TreeNode* node, int val)
    {
        // note 这里会导致一部分的堆内存泄露(随想录上面在定义函数的时候使用了返回值，在当前节点为nullptr的时候创建新节点，其他时候返回node本身)
        TreeNode* temp = new TreeNode(val);
        // 比骄节点值 - 节点在这里一定不是nullptr
        if(node->val > val)
        {
           if(node->left != nullptr)
               traversal(node->left,val);
           else
               node->left = temp;
        }

        if(node->val < val)
        {
            if(node->right != nullptr)
                traversal(node->right,val);
            else
                node->right = temp;
        }


    }

    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if(root == nullptr)
        {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        traversal(root, val);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution701;
int main() {
    Solution solution = Solution();

    return 0;
}

