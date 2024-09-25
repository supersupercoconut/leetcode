//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution104{
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

// 使用二叉树中定义的高度来从下往上遍历，计算出的高度与深度本质相同
int traversal(TreeNode* treeNode)
{
    // 自己想的大部分都是对的，但是对于高度变化上忘了直接+1
    int left = 0;
    int right = 0;
    if(treeNode->left) left = traversal(treeNode->left);
    if(treeNode->right) right = traversal(treeNode->right);
    int height = left > right ? left : right;
    // 返回值是当前treeNode的高度值，所以最后可以直接拿这个数据输出
    return ++height;
}
// 这里无论是深度优先还是广度优先遍历在这里都需要寻找到最深的叶子节点
class Solution {
public:
    int maxDepth(TreeNode* root)
    {

    /*** 层序遍历实现 ***/
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
//                if(temp->left != nullptr) q.push(temp->left);
//                if(temp->right != nullptr) q.push(temp->right);
//                size--;
//            }
//        }
//        return res;

        /*** 递归遍历实现 ***/
        if(root == nullptr) return 0;
        int res = traversal(root);
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution104;
int main() {
    Solution solution = Solution();

    return 0;
}