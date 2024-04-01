#include "../../../stdc.h"

using namespace std;



namespace solution232{
    //leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
/// 出栈时 如果为空，要将入栈中的所有元素都导入出栈(入栈不会保留该元素)(这样保证了一个元素要么就在出栈中，要么就保存在入栈中)
public:
    // 初始化的时候就定义两个栈 | 定义了两个空的栈元素
    stack<int> stack_in;
    stack<int> stack_out;

    MyQueue(){}
    
    void push(int x)
    {
        stack_in.push(x);
    }

    // 判断输出栈是不是空,不是空先处理输出栈 | 为空就先给输出栈导入元素再输出
    int pop()
    {
        if(stack_out.empty())
        {
            // 将stack_in的元素全部弹入
            while(!stack_in.empty())
            {
                int temp = stack_in.top();
                stack_in.pop();
                stack_out.push(temp);
            }
        }

        // 完成导入(但可能存在stack_in与stack_out同时为空的情况 | 这里得使用的时候注意)
        int temp = stack_out.top();
        stack_out.pop();
        return temp;
    }
    
    int peek()
    {
        // 可以使用该类中的方法，pop删除了这个元素 | 但是可以先弹出元素，再将该元素push进去
        int temp = this->pop();
        stack_out.push(temp);
        return temp;
    }
    
    bool empty()
    {
        if(stack_in.empty() && stack_out.empty())
            return true;
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
