//import universal *.h
#include "../../../stdc.h"

using namespace std;

namespace solution429{
    //leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        if(root == nullptr) return {};

        queue<Node*> q;
        vector<vector<int>> res = {};
        q.push(root);
        while( !q.empty() )
        {
            // 尝试一次循环就将一层level的数据处理掉
            vector<int> res_temp = {};
            int size = q.size();
            while(size > 0)
            {
                size--;
                Node* p = q.front();
                q.pop();
                for(auto v : p->children)
                {
                    if(v != nullptr)
                        q.push(v);
                }
                res_temp.push_back(p->val);
            }
            res.push_back(res_temp);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution429;
int main() {
    Solution solution = Solution();

    return 0;
}

