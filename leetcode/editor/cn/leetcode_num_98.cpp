//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution98{
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

/***
 *  1. 直白的思路(错误) : 不断的去分解为左右子树，然后不断地去计算(但是二叉搜索树不仅要求每一个子树都满足左小于中，中小于右，对子树与子树之间也有限制，所以这种做法失效)
 *  2. 最简单的思路即利用搜索二叉树的性质, 直接将整个二叉树按照中序遍历的顺序保存节点数据, 最终获取到的数据是一个升序遍历的数组
 *  3. 利用全局变量max_value将一个子树中的最大值与中间节点比较 | 最大值从左侧节点开始，只需要保证中间节点以及右侧节点都大于不断修改的最大值即可
 *  4. 还有另外一种方法即使用全局变量定义的pre指针(代替最大值的记录)，相当于在中序遍历中一直保证当前指针的val大于pre的val
 * ***/


class Solution {
public:
    // note 这里使用的max_value不能定义在class外面, 否则这个运行结果一直出现问题
    long long int max_value = 0x8000000000000000;  // 依然是手动设置64位最小值
    bool traversal(TreeNode* treeNode)
    {
        // 中序遍历逻辑 左中右
        // 处理左侧节点
        bool left = false;
        bool right = false;
        if(treeNode->left != nullptr)
            left = traversal(treeNode->left);

        if(max_value < treeNode->val) max_value = treeNode->val;
        else
            return false;

        if(treeNode->right != nullptr)
            right = traversal(treeNode->right);

        // 比较复杂逻辑 用于剔除掉treeNode左右子节点为空应该返回true实际返回false的情况
        if(treeNode->left == nullptr) left = true;
        if(treeNode->right == nullptr) right = true;
        return left && right;
    }


    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return false;
        return traversal(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution98;
int main() {
    Solution solution = Solution();
    TreeNode root(0);
    cout << solution.isValidBST(&root);
    return 0;
}

