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

// 层次遍历的方法最简单不需要解释, 对于递归方法实现, 因为不需要处理中间节点的数据，所以同一层中, 只要先处理到的节点就是最左侧的节点
/*
 * 1. 函数返回值为函数的层数
 * 2. 函数迭中的number为当前函数最左侧节点val值
 * */

// 题目的思路一开始想的就没有问题, 只是不知道深度值与数值如何一起返回(没有考虑unorder_map<>的方式, 再使用pair什么的) | 现在对应的整体逻辑有些问题, 谁做全局变量谁是函数返回值有些问题

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
class Solution {
public:
    int max_depth = 0x80000000; // 0x70000000是32位int对应的最大的正数, 其+1对应的是int所能表示最大负数的正数表示, 其取反+1之后对应的就是负数的表示
    int result = 0;
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
        traversal(root,1);
        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution513;
int main() {
    Solution solution = Solution();

    return 0;
}

