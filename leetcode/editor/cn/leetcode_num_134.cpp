//import universal *.h
#include "../../../stdc.h"

using namespace std;



namespace solution134{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /* 个人方法: (1) 最一开始的思路是使用回溯解决问题，但是这里与回溯针对组合或者排列问题不同的是，回溯问题是选中一个，n叉数下一层对应的是剩余的所有元素。
     *              但是这里明显是从[i]位置只能前往[i+1]的位置，故想在这里使用穷举方法，只需要两层for循环 */

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /* 暴力方法 */
//        for(int i = 0; i < gas.size(); ++i)
//        {
//            int vel = 0;        // 当前油量
//            int j = i;
//            while(1)
//            {
//                vel += gas[j];
//                vel -= cost[j];
//                // note 一定要注意这个部分，我自己定义的 j=0的写法在clion的编译器上可以通过但是在leetcode的编译器上就不能通过
//                j = (j + 1) % gas.size();
//                cout << vel <<' ';
//                if(vel < 0) break;
//                if(j == i) return i;
//            }
//        }
//        return -1;

        /* 贪心方法(计算每次加油站的结余量，即代码随想录中的方法) */
        /*
         *  (1) count < 0 即start 从 i + 1 开始，说明之前的rest[i]结余不够，一定是i或者i之前一段部分都取值为负数，这时候从前面选择start只会让正数变少，一定不对
         *  (2) total > 0 相当于保证整个数据里面是会出现解的
         *  (3) 因为解只会出现一次，这里从 i + 1 开始(之后肯定没有负数，要不然起始位置就不是从这里开始了) 在total大于等于0保证存在解的情况下，这是最可能是解的位置
         * */
        int count = 0;
        int total = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            count += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            // 这里未必只会出现一次 count小于0的情况，但是只要count < 0 就直接让 i 变为 i+1
            if(count < 0)
            {
                start = i + 1;
                count = 0;
            }

        }
        // 判断当前是否有解
        if(total < 0) return -1;
        else
            return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution134;
int main() {
    Solution solution = Solution();
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout <<  solution.canCompleteCircuit(gas,cost);
    return 0;
}

