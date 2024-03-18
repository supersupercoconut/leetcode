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
    // 使用双指针 | left指针 right指针先到index = n的位置，然后left与right一起移动直到right到最后一个元素处，那么left的下一个元素就可以被删除了
        // 并且需要添加虚拟头节点 dummy_head | 个人感觉使用虚拟的头节点可以避免一些情况下对于空指针访问的情况

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // 上面介绍了关于ListNode的初始化方法(要么是直接给val的值，要么是指针与val一起给)
        ListNode* dummy_head = new ListNode(0);
        if(head == nullptr)
            return nullptr;
        dummy_head->next = head;
        ListNode* left = dummy_head;
        ListNode* right = dummy_head;
        int count = 0;

        // 循环进行了n+1次
        while(right != nullptr && count<=n)
        {
            count++;
            right = right->next;
        }

//        // 这里判断如果right是最后一个元素 | 即说明n的大小与链表的长度是相等的，就不再变化left的位置
//        if(right->next != nullptr)
//        {
//            left = left->next;
//        }

        // left会出现在需要删除元素的前一个位置
        while(right != nullptr)
        {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;

//        // 删除元素
//        ListNode* temp = left->next;
//        if(temp->next == nullptr)
//            left->next = nullptr;
//        else
//            left->next = temp->next;

        return dummy_head->next;

        // 删除元素感觉没有问题 | 直接赋值成nullptr应该没问题但是实际就是不对


        // 很失败的删除逻辑，这么写的删除逻辑在最后的一些条件判断上面存在着问题
//        if(head == nullptr)
//            return nullptr;
//

//
//        // right 会正好停留在index = 2的位置
//        while(right->next !=  nullptr && count<n)
//        {
//            count++;
//            right = right->next;
//        }
//
//        // left 会正好停留在到数第n+1个位置(但如果只有一个元素的话，left本身就在要删除的位置上)
//        while(right->next != nullptr)
//        {
//            left = left->next;
//            right = right->next;
//        }
//
//        // left对应的下一个元素需要被删除掉 | 这里需要判断是否left的下一个元素为空或者其他情况
//        if(left->next == nullptr)
//        {
//            return nullptr;
//        }
//        else
//        {
//            ListNode* temp = left->next;
//            if(temp->next == nullptr) left->next = nullptr;
//            else left->next = temp->next;
//        }
//
//
//        return head;
//            delete dummy_head;
//
//            return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution19;
int main() {
    Solution solution = Solution();

    return 0;
}
