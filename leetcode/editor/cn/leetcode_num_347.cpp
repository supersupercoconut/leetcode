//import universal *.h
#include "../../../stdc.h"

using namespace std;



namespace solution347{
    //leetcode submit region begin(Prohibit modification and deletion)
class my_compare
{
  public:
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2)
    {
        // 小顶堆 谁小谁在前面 | 返回true说明 p2的优先级比p1大
        return p1.second > p2.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
          // 对于之前不存在的数据, mp[nums[i]]在一开始的时候执行的是默认初始化 即赋值为0
          mp[nums[i]] ++;
        }

        // 自行实现优先级队列,并且完成排序 —— 设定compare函数，使用小顶堆排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, my_compare> pq;
        for(auto it : mp){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }

        // 在顶堆队列中不会提供遍历方式，只能从最上面的元素往下做便利分析
        vector<int> result;
        while(pq.size() != 0){
            result.push_back(pq.top().first);
            pq.pop();
        }

        vector<int> res;
        for(int i=0;i<result.size();i++){
            res.push_back(result[result.size()-1-i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

// note 在这里实现了一种大顶堆的方法 - 使用大顶堆与小顶堆之间的区别就是小顶堆只需要保证当前堆中的元素是k即可, 但是对于大顶堆而言，所有的元素都需要进入大顶堆中，其对应的弹出以及放入元素的耗时会更高一些
//class myComparison {
//    // 构建大顶堆
//public:
//    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
//        return a.second < b.second;
//    }
//};
//
//
//int main() {
//    // 前k个高频元素
//    vector<int> v = {1,1,1,2,2,3};
//    int k = 2;
//    unordered_map<int,int> map;
//    for (int i = 0; i < v.size(); i++) {
//        map[v[i]] ++;
//    }
//
//    priority_queue<pair<int,int>, vector<pair<int,int>>, myComparison> pq;
//    for (auto i : map) {
//        pq.push(make_pair(i.first,i.second));
//    }
//
//    vector<int> res;
//    while (k--) {
//        res.push_back(pq.top().first);
//        pq.pop();
//    }
//
//    for (auto i : res) {
//        cout << i << " ";
//    }
//
//    return 0;
//}

using namespace solution347;
int main() {
    Solution solution = Solution();
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    solution.topKFrequent(nums,k);
    return 0;
}
