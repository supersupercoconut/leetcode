//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution257{
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

// 本题目没有想象中困难, 具体而言是直接将往下遍历的path作为参数进行递推使用 -> 为了节省资源, path参数是以引用的方法加入进去同时使用pop进行回溯(所谓的回溯不过是在这里引入了pop_back将之前的path进行清理)
void traversal(TreeNode* treeNode, vector<int>& path, vector<string>& result)
{
    // 处理过程
    path.push_back(treeNode->val);
    if(treeNode->left == nullptr && treeNode->right == nullptr) {
        string temp = {};
        // 比较冗余的string处理
        for(int i = 0; i < path.size(); ++i)
        {
            if(i == path.size()-1)
            {
                temp = temp + to_string(path[i]);
                continue;
            }
            else
                temp = temp + to_string(path[i]) + "->";
        }
        result.push_back(temp);
    }

    if(treeNode->left)
    {
        traversal(treeNode->left,path,result);
        path.pop_back();
    }
    if(treeNode->right)
    {
        traversal(treeNode->right,path,result);
        path.pop_back();
    }
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(root == nullptr) return {};
        vector<int> path;
        vector<string> result;
        traversal(root,path,result);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution257;
int main() {
    Solution solution = Solution();

    return 0;
}

