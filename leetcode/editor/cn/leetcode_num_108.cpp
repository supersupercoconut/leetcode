//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution108{
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

// 高度平衡二叉搜索树的处理(由于是有序数组，整理成为二叉树比较简单，转换成为高度平衡的二叉树就需要选择中间点将数组分割开-一边一半数据，然后用中间点当中间节点，这样就保证高度平衡)

class Solution {
public:

    /** 1. 个人方法(过于啰嗦) **/
    TreeNode* construct_tree(vector<int>&nums, int left, int right)
    {
        // 返回中间节点
        int mid = (right+left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        if(left >= right) return node;

        // 设置这部分的操作是因为mid一般是偏向于前一个点的，由于是有序数组，其左侧应该直接为nullptr即出现了left == mid的判断 | 对于right，这种现象是不会出现的 2个元素，left == mid 一个元素 left == right 三个及三个以上数据还需要分类
        if(left == mid)
            node->left = nullptr;
        else
            node->left = construct_tree(nums,left,mid-1);

        node->right = construct_tree(nums,mid+1,right);
        return node;
    }

    /** 2. 代码随想录中的方法(虽然与我使用的都是左闭右闭的区间, 但是比我更加简洁) **/
    TreeNode* traversal(vector<int>&nums, int left, int right)
    {
        // 随想录中的思路一般不在进入traversal()递归时进行条件限制, 而是在进入函数之后再做限制(确实对于简化代码有帮助)
        if(left > right) return nullptr;
        int mid = left + (right-left)/2;    // 绝不能携程 left/2 + right/2
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = traversal(nums,left,mid-1);
        node->right = traversal(nums,mid+1,right);
        return node;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int left = 0;
        int right = nums.size()-1; // 左闭右闭
        /* 个人方法 */
//        return construct_tree(nums,left,right);
        /* 随想录 */
        return traversal(nums,left,right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution108;
int main() {
    Solution solution = Solution();

    return 0;
}

