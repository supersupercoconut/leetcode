//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution637{
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return {};
        vector<double> res_level;
        queue<TreeNode*> q;
        int size = 1;
        double arg = 0;
        int n = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            size--;
            n++;
            arg += (node->val - arg)/n;
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
            // 判断是不是这一层的最后一个元素
            if(size == 0)
            {
                size = q.size();
                res_level.push_back(arg);
                arg = 0;
                n = 0;
            }
        }
        return res_level;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution637;
int main() {
    Solution solution = Solution();

    return 0;
}
