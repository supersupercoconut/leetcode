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
    // 判断是否出现 环形链表 | 使用两个指针 一个每一步前进两次 一个每一步前进一次 | 这样如果存在环，两个指针必然会相遇 | 返回的元素是如环的第一个节点
    ListNode *detectCycle(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        // 由于后面会访问head中的元素，所以要提前判断head是不是为空
        // fast进行限制，因为fast是需要往下查找的, 不能只限制下一个元素是不是空，还得去限制当前元素也不能为空 还是存在着访问nullptr进行限制的可能
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                // 寻找相对应的位置 现在定义一个从头开始的指针 与slow指针相遇的点就是我们需要的位置
                ListNode* temp = head;
                while(temp != slow && temp != nullptr && slow != nullptr )
                {
                    temp = temp->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        // 退出循环就认为没有环
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
