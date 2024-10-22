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

        for(int i = 0; i < gas.size(); ++i)
        {
            int vel = 0;        // 当前油量
            int j = i;
            while(1)
            {
                vel += gas[j];
//                if( j >= gas.size() ) j = 0;
                vel -= cost[j];
//                j++;
                // note 一定要注意这个部分，我自己定义的 j=0的写法在clion的编译器上可以通过但是在leetcode的编译器上就不能通过
                j = (j + 1) % gas.size();
                cout << vel <<' ';
                if(vel < 0) break;
                if(j == i) return i;
            }
            cout << endl;
//            cout << i << " ";
        }
        return -1;
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

