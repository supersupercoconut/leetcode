//import universal *.h
#include "../../../stdc.h"
using namespace std;
namespace solution501{
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
    /*** 1. 个人思路，使用多余的空间(使用deque双端队列来模拟了一个单调队列), 在使用中先遍历二叉树，分别使用一个记录数据以及频率, 来保证留在队列中的元素出现的频率都是最大且相等的 ***/
//    deque<int> num_queue = {};
//    deque<int> fre_queue = {};
//    int fre = 0;     // 频率
//    int now_val = 0; // 当前在记录的val值
//
//    // 新函数，用于整理队列元素(由于都是class内部的成员以及函数，所以不需要使用返回值以及形参)
//    // 具体作用是形成单调队列，放高频元素在其中 | 在二叉搜索树只能使用中序遍历
//    void queue_modify()
//    {
//        while(!fre_queue.empty())
//        {
//            auto temp = fre_queue.front();
//            if(temp > fre) break;
//            else if(temp == fre)
//            {
//                fre_queue.push_back(fre);
//                num_queue.push_back(now_val);
//                break;
//            }
//            else
//            {
//                fre_queue.pop_back();
//                num_queue.pop_back();
//            }
//        }
//
//        if(fre_queue.empty())
//        {
//            fre_queue.push_back(fre);
//            num_queue.push_back(now_val);
//        }
//    }
//
//
//    void traversal(TreeNode* node)
//    {
//        if(node->left != nullptr)
//            traversal(node->left);
//
//        // 程序刚开始
//        if(fre == 0 && now_val == 0)
//        {
//            now_val = node->val;
//            fre++;
//        }
//        // 不相等的时候，将上一次的fre以及node值放入队列中
//        else if(now_val != node->val)
//        {
//            // 记录数据发生变化, fre以及now_val都需要进栈处理
//            queue_modify();
//            now_val = node->val;
//            fre = 1;
//        }
//        else
//            fre++;
//
//        if(node->right != nullptr)
//            traversal(node->right);
//    }

    /* 2. 双指针方法 */
    // 使用一个最大值maxCount来统计频率, count来记录当前数据值
    int maxCount = 0;
    int count = 0;
    TreeNode* pre = nullptr;
    vector<int> result;
    void twoPtr_traversal(TreeNode* node)
    {
        if(node->left)
            twoPtr_traversal(node->left);


        if(pre == nullptr)
        {
            // 上一步会保证移动到最左侧节点处, 这里就是pre的出发点
            count = 1;
        }
        else
        {
            if(node->val == pre->val)
                count++;
            else
                count = 1;
        }
        pre = node;

        /* 这种方法的好处count获取到的数据永远是当前值的计数，无论其pre与node是不是相等 | 不相等,最大相等计数在上一次循环中就已经计算到result了，当前最大相等数就是1 */
        if(count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(node->val);
        }
        else if(count == maxCount)
        {
            result.push_back(node->val);
        }


        if(node->right)
            twoPtr_traversal(node->right);
    }

    vector<int> findMode(TreeNode* root)
    {
        /* 1. 个人方法 */
//        if(root == nullptr) return {};
//        traversal(root);
//
//        // 程序bug 函数在退后一次推出之后fre没有放入到队列中(手动改正)
//        queue_modify();
//
//        vector<int> res = {};
//        while(!num_queue.empty())
//        {
//            res.push_back(num_queue.front());
//            num_queue.pop_front();
//        }
//        return res;

        /* 2. 双指针方法 */
        if(root == nullptr) return {};
        twoPtr_traversal(root);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution501;
int main() {
    Solution solution = Solution();
    TreeNode root(1);
    TreeNode node_2(2);
    TreeNode node_3(2);

    root.left = nullptr;
    root.right = &node_2;

    node_2.left = nullptr;
    node_2.right = &node_3;

    auto temp = solution.findMode(&root);
    for(auto i : temp)
        cout << i << ' ';
    return 0;
}

