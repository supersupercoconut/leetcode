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

class Solution {
public:
    // 三刷链表反转的问题, 使用的方法还是一种双指针的方法
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* last = head;
        ListNode* cur = head->next;
        ListNode* next = cur;

        while(next != nullptr)
        {
            cur = next;
            next = cur->next;
            cur->next = last;
            if(last == head) last->next = nullptr;
            // 变换节点为下一次做准备
            last = cur;
        }
        return cur;
    }
};


//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//    /*** 双指针方法 ***/
//        // 给定虚拟的头节点来分析问题(这里是否使用虚拟头节点的意义不是很大)
////        if(head == nullptr) return nullptr;
////        ListNode* myHead = new ListNode(0, head);
////        ListNode* pre = myHead;
////        ListNode* cur = head;
////
////        while(cur != nullptr)
////        {
////            ListNode* tmp = cur->next;
////            // 设置的虚拟头节点并不能满足我们的需求，反转之后是不能出现虚拟的头节点的
////            if(pre == myHead)
////                cur->next = nullptr;
////            else
////                cur->next = pre;
////
////            pre = cur;
////            cur = tmp;
////        }
////
////        delete myHead;
////        return pre;
//
//        /*** 递归方法(为避免使用虚拟头节点导致的程序还需一步判断的方法，这里可以直接设置pre一开始为nullptr) ***/
//        return reverse(nullptr, head);
//    }
//
//    ListNode* reverse(ListNode* pre, ListNode* cur)
//    {
//        if(cur == nullptr) return pre;
//        else
//        {
//            ListNode* tmp = cur->next;
//            cur->next = pre;
//            // 互换位置
//            return reverse(cur, tmp);
//        }
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution206;
int main() {
    Solution solution = Solution();

    return 0;
}
