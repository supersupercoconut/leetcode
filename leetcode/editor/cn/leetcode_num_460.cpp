#include "../../../stdc.h"

using namespace std;

namespace solution460{
    //leetcode submit region begin(Prohibit modification and deletion)

struct Node
{
    int val;
    int key;
    int cnt;
    Node* next;
    Node* last;
    Node() = default;
    Node(int _key, int _val, int _cnt) : key(_key), val(_val), cnt(_cnt)
    {
        next = nullptr;
        last = nullptr;
    }
};

struct twoList
{
    int size;
    Node* head;
    Node* tail;
    twoList()
    {
        size = 0;
        head = new Node(0, 0, 0);
        tail = new Node(0,0,0);
        head->next = tail;
        tail->last = head;
    }

    twoList(Node* tmp)
    {
        size = 1;
        head = new Node(0, 0, 0);
        tail = new Node(0,0,0);
        head->next = tmp;
        tmp->last = head;
        tmp->next = tail;
        tail->last = tmp;
    }

    ~twoList()
    {
        delete head;
        delete tail;
    }
};


class LFUCache {
public:
    // note 在这里使用优先级队列时不能实现O(1)的push操作的, 这里的思路是补充一个unordered_map, 其中保存的是freq(使用次数)到一个双向链表的索引(因为对于相同使用次数的Node，需要按照LRU中的最近最少使用来清理内存)
    int min_freq = 0;
    int m_size = 0;
    int m_capacity = 0;
    unordered_map<int, twoList*> freq_map;
    unordered_map<int, Node*> key_map;

    // 将当前cnt对应的双向链表中移除该元素, 并将其移动到下一个cnt值对应的链表中, 判断当前是否会影响最小索引值
    void move(Node* tmp)
    {
        tmp->next->last = tmp->last;
        tmp->last->next = tmp->next;
        freq_map[tmp->cnt]->size--;
        if(freq_map[tmp->cnt]->size == 0 && tmp->cnt == min_freq)
            ++min_freq;

        auto a = ++ tmp->cnt;
        if(freq_map.find(a) != freq_map.end())
        {
            // 放到tail位置
            auto cur_list = freq_map[a];
            cur_list->size++;
            auto _node = cur_list->tail->last;
            _node->next = tmp;
            tmp->last = _node;
            tmp->next = cur_list->tail;
            cur_list->tail->last = tmp;
        }
        else
        {
            // 创建新的双向链表并导入数据
            auto new_list = new twoList(tmp);
            freq_map[a] = new_list;
        }
    }

    LFUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(key_map.find(key) != key_map.end())
        {
            // 更新当前节点
            auto tmp = key_map[key];
            move(tmp);
            return tmp->val;
        }
        else
            return -1;
    }
    
    void put(int key, int value)
    {
        if(key_map.find(key) != key_map.end())
        {
            key_map[key]->val = value;
            move(key_map[key]);
        }
        else
        {
            // 判断是否超过了元素上限
            if(key_map.size() >= m_capacity)
            {
                // 弹出元素 list 与 key_map都要进行数据删除 - 最小值对应的双向队列中head的下一个元素直接删除
                auto _list = freq_map[min_freq];
                _list->size--;
                auto _node = _list->head->next;
                _list->head->next = _node->next;
                _node->next->last = _list->head;

                key_map.erase(_node->key);
                if(_list->size == 0)
                    freq_map.erase(min_freq);
            }

            auto _node = new Node(key, value,1);
            min_freq = 1;
            // 判断是否有 cnt = 1的双端队列
            if(freq_map.find(_node->cnt) != freq_map.end())
            {
                auto _list = freq_map[_node->cnt];
                _list->size++;
                auto a = _list->tail->last;
                a->next = _node;
                _node->last = a;
                _list->tail->last = _node;
                _node->next = _list->tail;
            }
            else
            {
                // 创建队列
                auto _list = new twoList(_node);
                freq_map[_node->cnt] = _list;
            }
            // 为key_map补充元素
            key_map[key] = _node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution460;
int main() {
    Solution solution = Solution();

    return 0;
}
