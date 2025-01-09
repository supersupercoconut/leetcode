#include "../../../stdc.h"

using namespace std;

namespace solution203{
    //leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        // 利用虚拟头节点
        if(head == nullptr) return nullptr;
        ListNode* myHead = new ListNode();
        ListNode* cur = head;

        myHead->next = head;

        ListNode* pre = myHead;

        while(pre->next != nullptr)
        {
            cur = pre->next;
            if(cur->val == val)
                pre->next = cur->next;
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }


        head = myHead->next;
        delete myHead;
        return head;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution203;
int main() {
    Solution solution = Solution();

    return 0;
}
