//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution107{
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
  // 代码随想录中给出来的思路很简单，本质上就是将按循环的层次遍历生成结果按照反转输出 | 或者按照笨方法，队列中保留数据，但是对size的取值需要更关注一下
    vector<vector<int>> levelOrderBottom(TreeNode* root){
      if(root == nullptr) return {};
      vector<vector<int>> res;
      vector<int> res_level;
      queue<TreeNode*> q;
      int size = 1;
      q.push(root);
      while(!q.empty()){
        TreeNode* node = q.front();
		res_level.push_back(node->val);
        q.pop();
        size--;
        if(node->left != nullptr){
			q.push(node->left);
        }
		if(node->right != nullptr){
			q.push(node->right);
		}
		if(size == 0)
        {
            size = q.size();
            res.push_back(res_level);
            res_level.clear();
        }
      }
      // 比较简单的反转函数进行数据输出
      reverse(res.begin(), res.end());
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution107;
int main() {
    Solution solution = Solution();

    return 0;
}
