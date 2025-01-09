#include "../../../stdc.h"
using namespace std;
namespace solution142{
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
    ListNode *detectCycle(ListNode *head)
    {
        // 直接判断是否存在一个环的操作比较简单 - fast指针的速度为slow指针速度为两倍(其从原理上发现只会多走一圈) 随想录上有有一个数学解释 : 2(x+y) = x + y + (y+z) 那么 x = z, 故直接从链表相交的点与头节点开始移动既可
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr)
        {
            slow = slow->next;
            // 判断是否出现fast->next为空
            if(fast->next == nullptr) break;
                fast = fast->next->next;

            if(fast == slow)
            {
                // 证明有环出现
                ListNode* tmp_1 = head;
                ListNode* tmp_2 = fast;
                while(tmp_1 != nullptr && tmp_2 != nullptr)
                {
                    if(tmp_1 == tmp_2) return tmp_1;
                    else
                    {
                        tmp_1 = tmp_1->next;
                        tmp_2 = tmp_2->next;
                    }
                }
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution142;
int main() {
    Solution solution = Solution();

    return 0;
}
