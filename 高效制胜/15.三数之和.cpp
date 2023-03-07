/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序 + 双指针
        // 时间O(n^2) 其中 N 是数组 nums 的长度。
        // 空间O(logN)  我们忽略存储答案的空间，额外的排序的空间复杂度为 O(log⁡N)。然而我们修改了输入的数组 nums，
        // 在实际情况下不一定允许，因此也可以看成使用了一个额外的数组存储了 nums 的副本并进行排序，空间复杂度为 O(N)。
        
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b                            
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证b的指针在c的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着b后续的增加
                // 就不会有满足 a + b + c = 0 并且 b < c 的 c 了，可以退出循环    
                if (second == third) {
                    break;
                }         
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }                                                                            
            }
        }
        return ans;
    }
};
// @lc code=end

