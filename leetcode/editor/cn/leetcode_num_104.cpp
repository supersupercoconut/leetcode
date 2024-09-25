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

// 这里无论是深度优先还是广度优先遍历在这里都需要寻找到最深的叶子节点
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            res++;
            while(size > 0)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
                size--;
            }
        }
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