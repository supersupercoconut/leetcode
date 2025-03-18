#include "../../../stdc.h"

using namespace std;


//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 3423 👎 0


namespace solution146{
    //leetcode submit region begin(Prohibit modification and deletion)

struct Node
{
    // 因为需要从链表反推map中的元素(方便后续的删除map中的元素), 所以这里Node中也要保留key对应的元素，这样才能删除
    int key;
    int val;
    Node* next_ptr;
    Node* last_ptr;
    Node() = default;
    Node(int key, int val) : key(key), val(val)
    {
        next_ptr = nullptr;
        last_ptr = nullptr;
    }
};

class LRUCache {
public:

    //  本问题实现O(1)的get与put：get即可以使用一个unordered_map进行快速地查找 |
    //      put需要将最近使用的元素快速的移动到链表的最后位置, 在快速改变这个链表元素的时候使用双向链表是最合适的,即如果这里是一个单向链表这里改变链表节点对应位置的时候时间复杂度就不再是O(1)

    LRUCache(int capacity) {
        m_capacity = capacity;
        header = new Node(0, 0);
        tailer = new Node(0, 0);
    }

    // 将一个Node移动到最后的位置 即tailor之前
    void move(int key)
    {
        auto tmp = m[key];
        if(tmp->last_ptr != nullptr && tmp->next_ptr != nullptr)
        {
            tmp->last_ptr->next_ptr = tmp->next_ptr;
            tmp->next_ptr->last_ptr = tmp->last_ptr;
            // 该元素被放置在最后的位置
            tailer->last_ptr->next_ptr = tmp;
            tmp->last_ptr = tailer->last_ptr;
            tailer->last_ptr = tmp;
            tmp->next_ptr= tailer;
        }
        else
        {
            tailer->last_ptr->next_ptr = tmp;
            tmp->last_ptr = tailer->last_ptr;
            tmp->next_ptr = tailer;
            tailer->last_ptr = tmp;
        }

    }

    int get(int key) {
        if(m.find(key) != m.end())
        {
            move(key);
            return m[key]->val;
        }
        else
            return -1;
    }
    
    void put(int key, int value)
    {
        if(m.find(key) != m.end())
        {
            m[key]->val = value;
            // 完成put之后，这个值应该被移动到最后
            move(key);
        }
        else
        {
            // 需要移除元素
            if(m.size() >= m_capacity && m.size() > 0)
            {
                // 移除元素
                m.erase(header->next_ptr->key);
                header->next_ptr = header->next_ptr->next_ptr;
                header->next_ptr->last_ptr = header;
            }
            // 创建新元素 并且将这个元素放在最后
            Node* tmp = new Node(key, value);
            m[key] = tmp;
            // 处理其创建的新节点的取值情况
            if(m.size() == 1)
            {
                // 当前只有一个节点出现
                header->next_ptr = tmp;
                tmp->last_ptr = header;
                tailer->last_ptr = tmp;
                tmp->next_ptr = tailer;
            }
            else
                move(key);
        }
    }

    unordered_map<int, Node*> m;
    int m_capacity;
    Node* header;
    Node* tailer;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution146;
int main() {
    Solution solution = Solution();

    return 0;
}
