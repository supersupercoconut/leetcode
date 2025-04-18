#include "../../../stdc.h"

using namespace std;


//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）： 
//
// 实现 MyQueue 类： 
//
// 
// void push(int x) 将元素 x 推到队列的末尾 
// int pop() 从队列的开头移除并返回元素 
// int peek() 返回队列开头的元素 
// boolean empty() 如果队列为空，返回 true ；否则，返回 false 
// 
//
// 说明： 
//
// 
// 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法
//的。 
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 1, 1, false]
//
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
// 
//
// 
// 
//
// 
//
// 提示： 
//
// 
// 1 <= x <= 9 
// 最多调用 100 次 push、pop、peek 和 empty 
// 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作） 
// 
//
// 
//
// 进阶： 
//
// 
// 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。 
// 
//
// Related Topics 栈 设计 队列 👍 1182 👎 0


namespace solution232{
    //leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
public:
  // 创建两个stack来实现
  stack<int> in_stack;
  stack<int> out_stack;
    MyQueue() {}
    
    void push(int x) {
      in_stack.push(x);
    }
    
    int pop() {
        if(out_stack.empty())
        {
          while(!in_stack.empty())
          {
            out_stack.push(in_stack.top());
            in_stack.pop();
          }
        }
        // 相比与随想录上面的思路 这里其实不用再次判断数据可能异常的情况
        if(!out_stack.empty())
        {
          int tmp = out_stack.top();
          out_stack.pop();
          return tmp;
        }
        return -1;
    }

    // 这里暂时没有想要比较work的代码复用的情况，除非继续加入其他函数进行处理
    int peek() {
      if(out_stack.empty())
      {
        while(!in_stack.empty())
        {
          out_stack.push(in_stack.top());
          in_stack.pop();
        }
      }

      if(!out_stack.empty())
      {
        int tmp = out_stack.top();
        return tmp;
      }

      return -1;
    }
    
    bool empty() {
      if(out_stack.empty() && in_stack.empty()) return true;
      else
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution232;
int main() {
    Solution solution = Solution();

    return 0;
}
