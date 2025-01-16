#include "../../../stdc.h"

using namespace std;
namespace solution454{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
//        // TODO 最终这部分对应的时间是超时的... 正常结果是可以直接优化成为O(n^2)但是我只优化到了O(n^3)
//        // HASH表可以将O(n^4)转换成为O(n^3) 遍历其中三种情况然后分析最后一种对应的情况
//
//        unordered_map<int, vector<int>> search; // first为值 second为index下标
//        // 这里是直接使用unordered_map的属性直接处理，并不需要判断当前这nums[i]的取值问题
//        for(int i = 0; i < nums4.size(); ++i)
//        {
////            if(search.find(nums4[i]) != search.end())
//                search[nums4[i]].push_back(i);
////            else
////                search.insert({nums4[i], {i}});
////                search[nums4[i]].push_back(i);
////                search.insert({nums4[i], {i}});
//        }
//
//        for(auto i : search)
//        {
//            cout << i.first << ": ";
//            for(auto j : i.second)
//            {
//                cout << j << " ";
//            }
//            cout << endl;
//        }
//
//        int count = 0;
//        for(int i = 0; i < nums1.size(); ++i)
//        {
//            for(int j = 0; j < nums2.size(); ++j)
//            {
//                for(int k = 0; k < nums3.size(); ++k)
//                {
//                    if(search.find( -(nums1[i] + nums2[j] + nums3[k]) ) != search.end())
//                    {
//                        for(auto a : search[-(nums1[i] + nums2[j] + nums3[k])])
//                            ++count;
//                    }
//                }
//            }
//        }
//
//        return count;

    // 根据随想录上的思路 ： 先分析其A+B的所有可能取值对应的次数 后再遍历C+D结果中计算其最终结果对应的可能数量 这样确实将一个O(n^4)的算法降低到了O(n^2)
        int count = 0;
        unordered_map<int, int> search_map;
        for(auto i : nums1)
        {
            for(auto j : nums2)
                search_map[i + j]++;
        }

        for(auto i : nums3)
        {
            for(auto j : nums4)
            {
                if(search_map.find( -(i+j) ) != search_map.end())
                    count += search_map[-(i+j)];
            }
        }

        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution454;
int main() {
    Solution solution = Solution();

    return 0;
}
