#include "../../../stdc.h"

using namespace std;
namespace solution23{
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

//class myComprasion
//{
//public:
//    bool operator()(ListNode* a, ListNode* b)
//    {
//        return a->val > b->val;
//    }
//};
//
//
//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists)
//    {
//        // 分析多个升序链表的合并(hard问题, 两个链表合并可以直接使用双指针方法进行解决) -- 对于多种序列其可以直接使用优先级队列来快速实现 将整体的时间复杂度从O(n^3)降低成为O(n*n*log(n))
//        priority_queue<ListNode*, vector<ListNode*>, myComprasion> que;
//        vector<int> used(lists.size(), 0);
//        // 遍历lists
//        for(int i = 0; i < lists.size(); ++i)
//        {
//            auto it = lists[i];
//            while(it != nullptr)
//            {
//                que.push(it);
//                it = it->next;
//            }
//        }
//
//        // 遍历整个que队列,实现整体的逻辑
//        ListNode res(0, nullptr);
//        ListNode* cur = &res;
//        while(!que.empty())
//        {
//            auto tmp = que.top();
//            cout << tmp->val << endl;
//            cur->next = tmp;
//            que.pop();
//            cur = cur->next;
//        }
//        return res.next;
//    }
//};

class myComprasion
{
public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val; // 小顶堆：值小的优先级更高
    }
};

class Solution {
public:
    // TODO 没有想清楚之前的解决方法有什么问题 - 当然由于优先级队列中每输入以及弹出一个元素都有一个O(log n)的时间消耗，所以维持优先级队列的数量要越小越好，但是这不是之前方法内存泄漏的原因
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // 优先级队列：按节点值升序排列（小顶堆）
        priority_queue<ListNode*, vector<ListNode*>, myComprasion> que;

        // 将每个链表的头节点压入队列
        for (auto node : lists)
        {
            if (node) que.push(node);
        }

        // 创建结果链表的虚拟头节点
        ListNode dummy(0);
        ListNode* cur = &dummy;

        // 持续弹出优先队列的最小节点，构建结果链表
        while (!que.empty())
        {
            auto tmp = que.top(); // 取出堆顶节点
            que.pop();
            cur->next = tmp;      // 将堆顶节点连接到结果链表
            cur = cur->next;      // 移动结果链表指针

            if (tmp->next) que.push(tmp->next); // 将下一个节点压入队列
        }

        return dummy.next;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
}

using namespace solution23;
int main() {
    Solution solution = Solution();

    return 0;
}
