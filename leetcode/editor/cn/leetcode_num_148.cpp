#include "../../../stdc.h"

using namespace std;


//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
// 
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 2456 👎 0


namespace solution148{
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

// 查找中间节点(我这种方法虽然可以解决头节点的问题，但是目前来看寻找中间节点的方法还是直接给定首尾元素之后去遍历比较简单)
//    ListNode* searchMid(ListNode* head)
//    {
//        if(head == nullptr) return nullptr;
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while(fast->next != nullptr)
//        {
//            if(fast->next != nullptr) fast = fast->next->next;
//            if(fast != nullptr)
//                slow = slow->next;
//            else
//                break;
//        }
//        return slow;
//    }

    // 寻找中间节点, 并递归完成合并
//    ListNode* sortList(ListNode* head, ListNode* tail)
//    {
//        // 如果输入一个节点或者没有节点，即返回头元素即可
//        if(head == nullptr) return head;
//        // note 由于后面merge部分slow同时给了两个slowList函数, 说明这里其实是一个左闭右开的区间
//            // 一开始给的tail是nullptr 但是后面tail在递归中会变成非空值, 所以这里需要手动切割 防止tail的元素被同时使用了两次
//        if(head->next == tail)
//        {
//            head->next = nullptr;
//            return head;
//        }
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while(fast != tail)
//        {
//            slow = slow->next;
//            fast = fast->next;
//            if(fast != tail) fast = fast->next;
//        }
//        return merge(sortList(head, slow), sortList(slow, tail));
//    }

        // note 这种思路比leetcode上给的思路更加清除 sortList()要遵循的一个原则就是要么都是左闭右开 要么都是左闭右闭 这两个不能同时出现出来!!
        ListNode* sortList(ListNode* head, ListNode* tail) {
            if (head == tail || !head->next) return head; // 修正终止条件
            ListNode *slow = head, *fast = head->next;
            while (fast != tail && fast->next != tail) {  // 确保fast可以移动两步
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* mid = slow->next;
            slow->next = nullptr; // 正确断开链表
            ListNode* left = sortList(head, nullptr); // 递归排序左半部分
            ListNode* right = sortList(mid, nullptr);  // 递归排序右半部分
            return merge(left, right);
        }
    // note 这部分对应的合并部分相当于是最简单的部分 - 多链表合并也可以直接使用优先级队列实现
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* myHead = new ListNode(0, nullptr);
        ListNode* tmp = myHead;
        while(head1 != nullptr && head2 != nullptr)
        {
            if(head1->val > head2->val)
            {
                tmp->next = head2;
                head2 = head2->next;
            }
            else
            {
                tmp->next = head1;
                head1 = head1->next;
            }
            tmp = tmp->next;
        }
        if(head1 != nullptr) tmp->next = head1;
        else
            tmp->next = head2;
        // 这里将虚拟头头节点作为返回值
        auto res = myHead->next;
        delete myHead;
        return res;
    }

    // note 主要解决的方法是插值排序 将整个链表不断先进行分割，之后再将其进行合并
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution148;
int main() {
    Solution solution = Solution();

    return 0;
}
