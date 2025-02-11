#include "../../../stdc.h"

using namespace std;


//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。 
//
// 实现 MyStack 类： 
//
// 
// void push(int x) 将元素 x 压入栈顶。 
// int pop() 移除并返回栈顶元素。 
// int top() 返回栈顶元素。 
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。 
// 
//
// 
//
// 注意： 
//
// 
// 你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。 
// 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 2, 2, false]
//
//解释：
//MyStack myStack = new MyStack();
//myStack.push(1);
//myStack.push(2);
//myStack.top(); // 返回 2
//myStack.pop(); // 返回 2
//myStack.empty(); // 返回 False
// 
//
// 
//
// 提示： 
//
// 
// 1 <= x <= 9 
// 最多调用100 次 push、pop、top 和 empty 
// 每次调用 pop 和 top 都保证栈不为空 
// 
//
// 
//
// 进阶：你能否仅用一个队列来实现栈。 
//
// Related Topics 栈 设计 队列 👍 934 👎 0


namespace solution225{
    //leetcode submit region begin(Prohibit modification and deletion)
class MyStack {
public:
    // 注意这里的解决思路跟上一到文件不一样 这里的第二个队列仅仅只重叠数据保存的功能
    queue<int> q1 = {};
    queue<int> q2 = {};

    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop()
    {
        int res = 0;
        while(!q1.empty())
        {
            if(q1.size() == 1)
            {
                res = q1.front(); // 需要弹出的元素
                q1.pop();
                break;
            }
            q2.push(q1.front());
            q1.pop();
        }

        // note 这里相当于是直接进行转换， 一开始忘记了对于这种基本类似的数据，系统是会自己重载赋值运算符来进行转换的
        q1 = q2;
        while(!q2.empty())
            q2.pop();

        return res;
    }
    
    int top()
    {
        int res = 0;
        while(!q1.empty())
        {
            if(q1.size() == 1)
                res = q1.front(); // 需要弹出的元素
            q2.push(q1.front());
            q1.pop();
        }

        q1 = q2;
        while(!q2.empty())
            q2.pop();

        return res;
    }
    
    bool empty() {
        return q1.empty();
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