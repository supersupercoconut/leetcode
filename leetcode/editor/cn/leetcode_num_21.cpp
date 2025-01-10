#include "../../../stdc.h"
using namespace std;
namespace solution21{
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        // 使用left与right两个指针遍历各个链表
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* myHead = new ListNode(0, nullptr);
        ListNode* res = myHead;
        while(1)
        {
            while(left != nullptr && right != nullptr)
            {
                if(left->val > right->val)
                {
                    res->next = right;
                    right = right->next;
                }
                else
                {
                    res->next = left;
                    left = left->next;
                }

                // 变换指向
                res = res->next;
            }

            // 后续分析发现其中至少有一个指针不为空 —— 由于right与left仍然能保留其对应的后续数据，所以可以直接赋值即可 res->next = left中right不为空的元素
            res->next = (left == nullptr) ? right : left;
//            ListNode* tmp = (left == nullptr) ? right : left;
//            while(tmp != nullptr)
//            {
//                res->next = tmp;
//                res = res->next;
//                tmp = tmp->next;
//            }
            break;
        }

        ListNode* resu = myHead->next;
        delete myHead;
        return resu;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution21;
int main() {
    Solution solution = Solution();

    return 0;
}
