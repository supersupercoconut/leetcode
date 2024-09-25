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
class Solution {
public:
    int minDepth(TreeNode* root)
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
                if(temp->left == nullptr && temp->right == nullptr) return res;
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
                size--;
            }
        }
        // 这里感觉不会有什么用,一般都会出现叶子节点的
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution111;
int main() {
    Solution solution = Solution();

    return 0;
}