#include "../../../stdc.h"

using namespace std;

namespace solution496{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*** 单调栈原理简单，这里与739不一样的部分在于其需要处理的是数据值本身而不是序号
     *  (1) 单调栈与单调队列其实一样(按照取最大值举例)， 获取最大值的过程就是在不断地找一个子区间中谁最大
     *      假设存在一个大数，后面push进入的数都小于这个数，然后进来一个小于大数但是大于其他数的数，这个数即作为中间这堆数中最近大于其值的数，会按照自定义的逻辑进行处理 (这个数就是从第一个大数之后这个区间中的最大值)
     * ***/
    vector<int> res = {};
    stack<int> mystack = {};
    void backtracking(vector<int>& nums1, vector<int>& nums2)
    {
        res.assign(nums1.size(), -1);
        // 处理nums2，分析nums2中每一个元素后面的第一个更大的元素， 然后分析nums2的元素是否在nums1中, 作为最后的输出结果(无需保留序号)
        unordered_map<int, int> search;
        // 首先定义一个值，方便后续查找nums1中的元素
        for (int i = 0; i < nums1.size(); ++i)
            search.insert(pair<int,int>(nums1[i],-1));



        for(int i = 0; i < nums2.size(); ++i)
        {
            if (mystack.empty())
            {
                mystack.push(nums2[i]);
                continue;
            }

            if(nums2[i] < mystack.top() || nums2[i] == mystack.top())
                mystack.push(nums2[i]);
            else
            {
                while(mystack.size() != 0 && mystack.top() < nums2[i])
                {
                    // 需要判断当前这个元素是否是nums1中的元素
                    if(search.find(mystack.top()) != search.end())
                        search[mystack.top()] = nums2[i];
                    mystack.pop();
                }
                mystack.push(nums2[i]);
            }
        }

        // 对res需要的数据进行打包
        for(int i = 0; i < nums1.size(); i++)
            res[i] = search[nums1[i]];

    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) return {};
        backtracking(nums1, nums2);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution496;
int main() {
    Solution solution = Solution();
    vector<int> nums1 = {4,2,1};
    vector<int> nums2 = {1,3,4,2};
    solution.nextGreaterElement(nums1, nums2);

    for(auto i: solution.res)
        cout << i << ' ';
    return 0;
}
