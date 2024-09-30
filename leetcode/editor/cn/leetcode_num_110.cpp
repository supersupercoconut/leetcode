//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution110{
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

// 注意平衡二叉树指的是所有节点的左右子树高度差不能大于1 —— 这就要求对于所有的节点即在所有的遍历函数traversal()中都需要获取左右子树的高度然后判断, 这里是直接使用-1来表示bool中的false, true不显示表示
int traversal(TreeNode* treeNode)
{
    // 判断左右高度区别 (后序遍历+比较左右)
    int left = 0;
    int right = 0;
    if(treeNode->left) left = traversal(treeNode->left);
    if(left == -1 ) return -1;
    if(treeNode->right) right = traversal(treeNode->right);
    if(right == -1) return -1;

    // 实在没有想起来可以直接使用-1来表示, 一直想找如何将bool类型的数据与实际需要返回的深度同时获取
    int height = 0;
    if( ( (left-right) > 1) || ( (right-left) >1) )
        return -1;
    else
    {
        height = left > right ? left : right;
        return ++height;
    }
}


class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        if(root== nullptr) return true;
        int res = traversal(root);
        if(res == -1)
            return false;
        else
            return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution110;
int main() {
    Solution solution = Solution();

    return 0;
}

