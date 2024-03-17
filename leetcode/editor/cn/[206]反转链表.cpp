#include "../../../stdc.h"

using namespace std;



namespace solution206{
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

// 这里一开始范了一个大错误 | 指针变量本身是可以更换指向的元素的，但是其对应的那块地址改变之后，所有指向这块地址的指针都会发生改变
class Solution {
public:
    // 这里没有去自己定义一个头节点 | 而是直接使用两个指针进行链表的翻转
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr)
            return nullptr;

        ListNode* left = head;
        ListNode* right = head->next;
        //  如果只有head这一个元素 right也会为空
        while(right != nullptr)
        {
            ListNode* temp = right->next;
            right->next = left;
            left = right;
            right = temp;
        }

        head->next = nullptr;
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution206;
int main() {
    Solution solution = Solution();
    return 0;
}
