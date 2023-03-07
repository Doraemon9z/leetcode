/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 哈希表 
        // 时间复杂度O(n)  其中 N 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。
        // 空间复杂度O(n)  其中 N 是数组中的元素数量。主要为哈希表的开销。
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};




        // 暴力递归 时间复杂度O(n^2)  其中 NNN 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。
        // 空间复杂度O(1)

        /* int n = nums.size();
        for (int i = 0; i < n; ++i ) {
            for (int j = i + 1; j < n; ++j) {
                if(nums[i] + nums[j] ==target) {
                    return {i,j};
                }
            }
        }
        return {}; */
    }
};
// @lc code=end

