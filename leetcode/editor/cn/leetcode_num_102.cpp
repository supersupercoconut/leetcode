//import universal *.h
#include "../../../stdc.h"

using namespace std;



namespace solution102{
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
  // 主要是使用size进行处理 | size只有等这一层的数据全部被处理之后才会更新
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> res_temp;
        int size = 1;
        // 单项队列 FIFO
        queue<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* p = s.front();
            s.pop();
            res_temp.push_back(p->val);
            size--;

            if(p->left != nullptr){
                s.push(p->left);
            }
            if(p->right != nullptr){
                s.push(p->right);
            }

            if(size == 0){
                size = s.size();
                res.push_back(res_temp);
                res_temp.clear();
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution102;
int main() {
    Solution solution = Solution();

    return 0;
}
