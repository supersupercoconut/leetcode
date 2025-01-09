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
        // 直接判断时间复杂度为O(n+n+n) 空间复杂度为O(1)
        int n1 = 0,  n2 = 0;
        ListNode* tmp = headA;
        while(tmp != nullptr)
        {
            tmp = tmp->next;
            n1++;
        }

        tmp = headB;
        while(tmp != nullptr)
        {
            tmp = tmp->next;
            ++n2;
        }

        // 判断更大值
        ListNode* left = headA;
        ListNode* right = headB;

        if(n1 > n2)
        {
            int a = n1 - n2;
            while(a--)
                left = left->next;
        }

        else if(n1 < n2)
        {
            int a = n2 - n1;
            while(a--)
                right = right->next;
        }

        ListNode* res = nullptr;
        while(right != nullptr && left != nullptr)
        {
            if(right == left) return right;
            right = right->next;
            left = left->next;
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

