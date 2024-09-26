//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution111{
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

// 整体逻辑依然是后序遍历，先判断左右子树返回，然后判断出递归函数最终的返回值
int traversal(TreeNode* treeNode)
{
    int left = 0;
    int right = 0;
    if(treeNode->left) left = traversal(treeNode->left);
    if(treeNode->right) right = traversal(treeNode->right);
    // left或者right单独为0的时候即说明左子树或者右子树为nullptr, 需要单独判断
    int height = 0;
    if( left == 0 && right != 0 )
        height = right;
    else if( right == 0 && left != 0)
        height = left;
    else
        height = left > right ? right : left;
    return ++height;
}

class Solution {
public:
    int minDepth(TreeNode* root)
    {
        /*** 层次遍历实现 ***/
//        if(root == nullptr) return 0;
//        int res = 0;
//        queue<TreeNode*> q;
//        q.push(root);
//        while(!q.empty())
//        {
//            int size = q.size();
//            res++;
//            while(size > 0)
//            {
//                TreeNode* temp = q.front();
//                q.pop();
//                if(temp->left == nullptr && temp->right == nullptr) return res;
//                if(temp->left != nullptr) q.push(temp->left);
//                if(temp->right != nullptr) q.push(temp->right);
//                size--;
//            }
//        }
//        // 这里感觉不会有什么用,一般都会出现叶子节点的
//        return res;

        /*** 迭代遍历实现 ***/
        if(root == nullptr) return 0;
        return traversal(root);

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution111;
int main() {
    Solution solution = Solution();

    return 0;
}