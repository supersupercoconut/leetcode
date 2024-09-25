//import universal *.h
#include "../../../stdc.h"

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

namespace solution116{
    //leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            Node* temp;
            while(size > 0)
            {
                temp = q.front();
                q.pop();
                // 给定满子树
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
                size--;

                if(size == 0)
                    temp->next = nullptr;
                else
                    temp->next = q.front();
            }

        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution116;
int main() {
    Solution solution = Solution();

    return 0;
}