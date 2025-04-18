#include<iostream>
#include<vector>
using namespace std;

// note 排序算法不未必纠结与需要被对比的对象到底是一个数组对象还是一个链表对象, 个人其对应的方法是一样的

void Sort(vector<int>& v)
{
    /* 冒泡排序方法: i 代表的移动的次数(由于每一次是将当前最大的元素移动到最后, 所以一共需要移动v.size()-1次)
     *             j 代表的当前需要对比的元素，每执行一次i后续就可以少比较一个元素，所以其上限才被设定成为v.size()-1-i次 */
//    for(int i = 0; i < v.size() - 1; ++i)
//    {
//        for(int j = 0; j < v.size() - i - 1; ++j)
//        {
//            if(v[j] > v[j+1])
//                swap(v[j], v[j+1]);
//        }
//    }

    /* 快排 */

    for(auto i : v)
    {
        cout << i << " ";
    }
}

struct Node
{
    int m_val;
    Node* m_next;
    Node(int val, Node* next) : m_val(val), m_next(next){}
};


/* 归并排序(由于其是一种分而治之的策略，对于链表而言其分割一个子链表出来是非常简单的, 但是对于数组而言其分割子数组还是复杂) */
// 归并排序的合并函数
Node* merge(Node* left, Node* right) {
    Node dummy(0, nullptr); // 使用临时哑节点简化操作
    Node* ptr = &dummy;

    while (left && right) {
        if (left->m_val <= right->m_val) {
            ptr->m_next = left;
            left = left->m_next;
        } else {
            ptr->m_next = right;
            right = right->m_next;
        }
        ptr = ptr->m_next;
    }

    ptr->m_next = (left ? left : right);
    return dummy.m_next;
}

// 归并排序主函数（修复后的分割逻辑）
Node* sortList(Node* head) {
    if (head == nullptr) return head;
    if (head->m_next == nullptr) return head;

    // 正确找到链表中点（快慢指针法）
    Node* slow = head;
    Node* fast = head->m_next;

    while (fast != nullptr && fast->m_next != nullptr)
    {
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }

    Node* mid = slow->m_next;
    slow->m_next = nullptr; // 切断链表
    // 递归排序子链表
    Node* left = sortList(head);
    Node* right = sortList(mid);
    return merge(left, right);
}

//int partition(vector<int>& nums, int left, int right)
//{
//    int i = left;
//    int j = right;
//    while(i < j)
//    {
//        if(nums[i] )
//
//
//    }
//}


//void quickSort(vector<int>& nums, int left, int right)
//{
//    if(left >= right) return;
//
//    int i = left;
//    int j = right;
//    while(i < j)
//    {
//        while(nums[i] < nums[left] && i < j) {
//            ++i;
//        }
//
//        while(nums[j] > nums[left] && i < j) {
//            --j;
//        }
//        swap(nums[i], nums[j]);
//    }
//    swap(nums[left], nums[i]);
//
//
//    for(auto a : nums)
//        cout << a << " ";
//    cout << endl;
//
//
//    // i位置为中间位置
//    quickSort(nums, left, i-1);
//    quickSort(nums,i+1, right);
//}

// index为当前需要被插入的元素 从0~index为需要被插入元素的部分 | 关于插入排序实际上是可以存在更简单的表示方法, 但对应的时间复杂度还是O(n^2)
void insertSort(vector<int>& nums, int index) {
    if (index >= nums.size() || index < 1) return;
    int i = 0;

    while (i < index && nums[i] <= nums[index])
        ++i;


    int j = index - 1;
//    if(j >= i)
//    {
        int tmp = nums[index];
        while(j >= i)
        {
            nums[j+1] = nums[j];
            --j;
        }
        nums[i] = tmp;
//    }


    for(auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;

    insertSort(nums, index + 1);
}



int main()
{
    vector<int> v = {1,5,12,3,19,2,15,4,9,10};
    /* 归并排序 */
//    Node dummy(0, nullptr);
//    Node* ptr = &dummy;
//    for (int num : v) {
//        ptr->m_next = new Node(num, nullptr);
//        ptr = ptr->m_next;
//    }
//
//    // 排序并输出
//    Node* sorted = sortList(dummy.m_next);
//    while (sorted) {
//        cout << sorted->m_val << " ";
//        Node* temp = sorted;
//        sorted = sorted->m_next;
//        delete temp; // 及时释放内存
//    }

    /* 快速排序 - 仿照sort()实现的排序 */
//    quickSort(v, 0, v.size()-1);

    insertSort(v, 1);


    for(auto i : v)
    {
        cout << i << " ";
    }


    system("pause");
    return 0;
}