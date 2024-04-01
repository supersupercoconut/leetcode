#include "../../../stdc.h"

using namespace std;


namespace solution225{
    //leetcode submit region begin(Prohibit modification and deletion)
class MyStack {
/// 只使用了一个队列来实现栈功能
public:
    queue<int> que;
    MyStack(){}

    void push(int x)
    {
        que.push(x);
    }

    // 默认其至少有一个元素
    int pop()
    {
        // 将最后一个元素之前的元素插入最后
        int count = 0;
        while(count < que.size()-1)
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
            count++;
        }

        // 判断是不是只有一个元素 | 只有一个元素就直接操作 | 多余元素要重新插入
        int temp = que.front();
        que.pop();
        return temp;
    }
    
    int top()
    {
        int temp = que.back();
        return temp;
    }

    // 相同逻辑就写的简单
    bool empty()
    {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution225;
int main() {
    Solution solution = Solution();

    return 0;
}
