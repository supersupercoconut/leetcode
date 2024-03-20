#include "../../../stdc.h"

using namespace std;

namespace solution160{
    //leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* result = new ListNode(0, nullptr);
        // 先遍历两个链表 找到两个链表的长度信息
        int count_A = 0;
        int count_B = 0;
        ListNode* temp_1 = new ListNode(0,headA);
        ListNode* temp_2 = new ListNode(0,headB);
        // 先遍历整个数组长度
        while(temp_1->next != nullptr)
        {
            temp_1 = temp_1->next;
            count_A++;
        }
        while(temp_2->next != nullptr)
        {
            temp_2 = temp_2->next;
            count_B++;
        }

        // 长度长的链表往前前进
        temp_1 = headA;
        temp_2 = headB;
        if(count_A >= count_B)
        {
            int temp = count_A-count_B;
            while(temp--)
                temp_1 = temp_1->next;
        }
        else
        {
            int temp = count_B-count_A;
            while(temp--)
                temp_2 = temp_2->next;
        }

        // 一切往前前进
        while(temp_2 != nullptr && temp_1 != nullptr)
        {
            if(temp_2 == temp_1 )
                return temp_2;
            else
            {
                temp_1 = temp_1->next;
                temp_2 = temp_2->next;
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution160;
int main() {
    Solution solution = Solution();

    return 0;
}
