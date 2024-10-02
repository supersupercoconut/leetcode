//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution513{
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
 * 1. 层次遍历最简单,尝试使用递归方法进行处理(递归第一次到深度最大的节点即可以认为是目标节点)
 * 2. 题目的思路一开始想的就没有问题, 只是不知道深度值与数值如何一起返回(没有考虑unorder_map<>的方式, 再使用pair什么的)
 * ***/

//int traversal(TreeNode* treeNode, int& number)
//{
//    int size = 0;
//    if(treeNode->left == nullptr && treeNode->right == nullptr)
//    {
//        number = treeNode->val;
//        return size+1;
//    }
//
//    int left, right;
//    if(treeNode->left) left = traversal(treeNode->left, treeNode->left->val);
//    if(treeNode->right) right = traversal(treeNode->right, treeNode->right->val);
//    left = ;
//    right = ;
//
//}


// TODO 发现一个问题 如果这两个 int max_depth = 0x80000000; int result = 0;不写在class类中的话,最终输出的结果一直不正常(很奇怪!!!!)
    int max_depth = 0x80000000; // 0x70000000是32位int对应的最大的正数, 其+1对应的是int所能表示最大负数的正数表示, 其取反+1之后对应的就是负数的表示
    int result = 0;

class Solution {
public:

    struct tree_res
    {
        int depth = 0x80000000;
        int res;
    };

    tree_res struct_traversal(TreeNode* treeNode)
    {
        if(treeNode->left == nullptr && treeNode->right == nullptr)
        {
            tree_res res_t;
            res_t.depth = 1;
            res_t.res = treeNode->val;
            return res_t;
        }

        tree_res left_res;
        tree_res right_res;

        if(treeNode->left)
            left_res = struct_traversal(treeNode->left);
        if(treeNode->right)
            right_res = struct_traversal(treeNode->right);

        /*** 复杂的条件判断 (struct中的depth需要默认成最小值) ***/
        if(left_res.depth >= right_res.depth)
        {
            left_res.depth += 1;
            return left_res;
        }
        else
        {
            right_res.depth += 1;
            return right_res;
        }
    }

    void traversal(TreeNode* treeNode, int depth)
    {
        if(treeNode->left == nullptr && treeNode->right == nullptr)
        {
            if(depth > max_depth)
            {
                result = treeNode->val;
                max_depth = depth;
            }
        }

        if(treeNode->left)
        {
            depth++;
            traversal(treeNode->left, depth);
            depth--;
        }

        if(treeNode->right)
        {
            depth++;
            traversal(treeNode->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode* root)
    {
        if(root == nullptr) return 0;
//        traversal(root,1);
//        return result;
        auto temp = struct_traversal(root);
        return temp.res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution513;
int main() {
    Solution solution = Solution();

    return 0;
}

