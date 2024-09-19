//import universal *.h
#include "../../../stdc.h"
using namespace std;

namespace solution199{
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
    // 整体流程 只会选出最右侧的元素，其余部分的元素不会被考虑
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res_level;
        queue<TreeNode*> q;
        int size = 1;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(size == 1)
                res_level.push_back(node->val);
            size--;

            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
            if(size == 0)
                size = q.size();
        }
        return res_level;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution199;
int main() {
    Solution solution = Solution();

    return 0;
}
