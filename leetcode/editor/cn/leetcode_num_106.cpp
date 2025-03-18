//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution106{
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

// note 这里涉及到了指针变量做内参以及返回值(都需要注意指针变量对应的内存是不是已经被释放掉了，尤其是充当返回值的时候，指针绝不能指向的是已经要被释放的局部变量)
// 二刷中, 一开始时没有想好数组如何进行切割，一开始想的时使用两个下标在原数组中进行操作，但是可能对逻辑的要求太强 倒不如直接去分割数组进行处理, 只会损失一定的空间复杂度

// 读取当前的中序与后序数组, 最后直接返回中间节点的指针(需要不断的new新的二叉树节点)
TreeNode* traversal2(vector<int>& inorder, vector<int>& postorder)
{
    if(inorder.empty() && postorder.empty()) return nullptr;
    // 后序节点的最后一个节点
    auto tmp = postorder[postorder.size()-1];
    TreeNode* node = new TreeNode(tmp);
    int index = 0;
    for(int i = 0; i < inorder.size(); ++i)
    {
        if(inorder[i] == tmp)
            index = i;
    }

    // note 注意这里定义数组的过程中
        // 1. end()返回的时最后一个元素之后的位置, 所以这里使用其他数组元素来给当前这个元素赋值中, 对应的是一个左闭右开的区间
        // 2. vector<int> in_left(inorder.begin(),inorder.begin() + index); 当前后区间的边界相等时, 其会直接定义一个空数组

    // 定义左右子数组
    vector<int> in_left(inorder.begin(),inorder.begin() + index);
    vector<int> in_right(inorder.begin() + index + 1, inorder.end());
    // 利用相同大小划分其余部分
    vector<int> post_left(postorder.begin(), postorder.begin() + in_left.size());
    vector<int> post_right(postorder.begin() + in_left.size(), postorder.end() - 1);

    node->left = traversal2(in_left, post_left);
    node->right = traversal2(in_right, post_right);

    return node;
}

//// in中序 pos后序 in_node每一次进函数都是获取到中间点
//TreeNode* traversal(vector<int>& in_array, vector<int>& pos_array)
//{
//    if(in_array.empty() || pos_array.empty())
//        return nullptr;
//
//    int in_val = pos_array[pos_array.size()-1];
//    TreeNode* in_node = new TreeNode(in_val);
//
//// 不能使用下面的写法 —— 会导致程序访问一个已经被释放的栈内存
////    TreeNode temp(in_val);
////    TreeNode* in_node = &temp;
//
//    if(pos_array.size() == 1)
//        return in_node;
//
//
//    int i = 0;
//    vector<int> in_left;
//    vector<int> in_right;
//
//    // 中序数组划分
//    for(; in_array[i] != in_val; i++)
//        in_left.push_back(in_array[i]);
//    ++i;    // 跳过中间点
//    for(;i<in_array.size(); ++i)
//        in_right.push_back(in_array[i]);
//    // 后序数组划分
//    int j = 0;
//    vector<int> pos_left;
//    vector<int> pos_right;
//    for(; j < in_left.size(); ++j)
//        pos_left.push_back(pos_array[j]);
//    for(; j < pos_array.size()-1; ++j)
//        pos_right.push_back(pos_array[j]);
//
//    TreeNode* left = traversal(in_left, pos_left);
//    TreeNode* right = traversal(in_right, pos_right);
//
//    in_node->left = left;
//    in_node->right = right;
//
//    return in_node;
//}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        // 利用后序遍历数组以及中序遍历数组处理问题，整体逻辑就是找到中间节点，然后划分左右子树进行处理
        if(inorder.empty() || postorder.empty())
            return nullptr;

//        return traversal(inorder,postorder);
        return traversal2(inorder, postorder);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution106;
int main() {
    Solution solution = Solution();

    return 0;
}

