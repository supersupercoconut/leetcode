#include "../../../stdc.h"

using namespace std;


//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
//
// Related Topics 递归 链表 👍 2335 👎 0


namespace solution24{
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* pre = head;
        ListNode* cur = nullptr;
        ListNode* myHead = new ListNode(0, pre);

        ListNode* last = myHead;

        while(pre != nullptr)
        {
            cur = pre->next;
            if(cur == nullptr) break;

            // 均不为空，则可以进行交换
            pre->next = cur->next;
            cur->next = pre;
            last->next = cur;
            // 保留之前的头节点
            last = pre;
            pre = pre->next;
        }

        // 接受虚拟头节点的值
        ListNode* res = myHead->next;
        delete myHead;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution24;
int main() {
    Solution solution = Solution();

    return 0;
}
