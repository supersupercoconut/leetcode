#include "../../../stdc.h"

using namespace std;
namespace solution141{
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
    bool hasCycle(ListNode *head)
    {
        // 判断是否存在环但是不需要计算如环的头节点 —— 唯一的问题就是fast指针与slow指针可能越界
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow != nullptr && fast != nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr) return false;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution141;
int main() {
    Solution solution = Solution();

    return 0;
}
