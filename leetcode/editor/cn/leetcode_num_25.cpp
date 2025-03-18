#include "../../../stdc.h"

using namespace std;


//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
//
// Related Topics 递归 链表 👍 2510 👎 0


namespace solution25{
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // note 首先第一种解决思路即利用栈来处理问题 先判断当前链表中的节点数据然后分析其对应的数据 PS: 这个栈思路真的是非常简单！！
//        ListNode* myHead = new ListNode(0);
//        myHead->next = head;
//        ListNode* cur = head;
//        int num = 0;
//        while(cur != nullptr)
//        {
//            ++num;
//            cur = cur->next;
//        }
//
//        cur = myHead->next;
//        stack<ListNode*> s;
//        ListNode* res = myHead;
//        for(int i = 0; i < num / k; ++i)
//        {
//            for(int j = 0; j < k; ++j)
//            {
//                s.push(cur);
//                cur = cur->next;
//            }
//            // 当前cur自动出现在下一个起始的部分
//            while(!s.empty())
//            {
//                auto tmp = s.top();
//                s.pop();
//                res->next = tmp;
//                res = res->next;
//            }
//        }
//        res->next = cur;
//        res = myHead->next;
//        delete myHead;
//        return res;

        // note 如果想使用O(1)空间的时间复杂度, 就需要直接使用递归方法来解决类似的问题 —— 在递归中不进行数据的互换, 只进行节点next指针的变换
            // PS: 注意这里接受参数与输出参数的时候使用的都是 p->next 其实际上程序正常运行的关键
        ListNode* myHead = new ListNode(0);
        myHead->next = head;
        ListNode* cur = head;
        int num = 0;
        while(cur != nullptr)
        {
            ++num;
            cur = cur->next;
        }

        int s = 0;
        ListNode* p = myHead;
        while(++s < (num/k)*k)
        {
            if(s % k == 1)
                p->next = reverseKNode(p->next, k);

            p = p->next;
        }

        auto res = myHead->next;
        delete myHead;
        return res;

    }

    ListNode* reverseKNode(ListNode* node, int k)
    {
        if(k == 1 || node->next == nullptr) return node;

        auto res = reverseKNode(node->next, k-1);
        auto p = node->next->next;
        node->next->next = node;
        node->next = p;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution25;
int main() {
    Solution solution = Solution();

    return 0;
}
