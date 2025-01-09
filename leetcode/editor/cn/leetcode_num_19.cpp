#include "../../../stdc.h"
using namespace std;
namespace solution19{
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        /*** 双指针方法解决类似问题(fast先前进n， 然后slow与fast同时移动直到fast到链表的末尾，此时slow指针对应的下一个元素处即为待求元素) ***/
        // 创建虚拟头节点(利用一个偷节点处理问题确实方便)
        ListNode* myHead = new ListNode(0, head);
        ListNode* fast = myHead;
        ListNode* slow = myHead;
        while(n--)
        {
            if(fast != nullptr)
                fast = fast->next;
        }

        // fast与slow同时移动，直到fast走到了最终的末尾元素处
        while(fast != nullptr)
        {
            fast = fast->next;
            if(fast == nullptr) break;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        head = myHead->next;
        delete myHead;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution19;
int main() {
    Solution solution = Solution();

    return 0;
}
