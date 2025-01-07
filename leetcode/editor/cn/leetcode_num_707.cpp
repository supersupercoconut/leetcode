#include "../../../stdc.h"

using namespace std;

namespace solution707{
    //leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {
public:
    MyLinkedList() {
        size = 0;
        myHead = new ListNode(0, nullptr);
    }
    
    int get(int index) {
        // index是从0开始计数的
        ListNode* cur = myHead;
        int count  = 0;
        while(cur->next != nullptr)
        {
            cur = cur->next;
            if(count == index)
                return cur->val;
            ++count;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = myHead->next;
        myHead->next = tmp;
        ++size;
    }
    
    void addAtTail(int val) {
        // 遍历到尾部补充元素
        ListNode* tmp = new ListNode(val);
        ListNode* cur = myHead;
        while(cur->next != nullptr)
            cur = cur->next;

        cur->next = tmp;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        // 遍历到当前元素处，而且是在index之前加
        if(index < 0) return;

        ListNode* cur = myHead;
        ListNode* pre = myHead;
        int count = 0;
        while(cur->next != nullptr)
        {
            cur = cur->next;
            if(count == index)
            {
                ListNode* node = new ListNode(val, pre->next);
                pre->next = node;
                ++size;
                return;
            }
            ++count;
            pre = cur;
        }

        // 判断index是否等于元素size
        if(index == size)
        {
            ListNode* node = new ListNode(val, pre->next);
            pre->next = node;
            ++size;
        }
    }
    
    void deleteAtIndex(int index) {
        // 遍历到当前元素处，而且是在index之前加
        if(index < 0) return;
        ListNode* cur = myHead;
        ListNode* pre = myHead;
        int count = 0;
        while(cur->next != nullptr)
        {
            cur = cur->next;
            if(count == index)
            {
                pre->next = cur->next;
                --size;
                return;
            }
            ++count;
            pre = cur;
        }
    }

    // 容量与虚拟头节点
    int size;
    ListNode* myHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution707;
int main() {
//    Solution solution = Solution();
    MyLinkedList* obj = new MyLinkedList();

    obj->addAtHead(7);


    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3,0);
    obj->deleteAtIndex(2);

    obj->addAtHead(6);
    obj->addAtTail(4);
    cout << obj->get(4) << endl;
    obj->addAtHead(4);
    obj->addAtIndex(5,0);
    obj->addAtHead(6);

    return 0;
}
