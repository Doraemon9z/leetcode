/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针优化
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                --right;
            } else {
                ++left;
            }
            
        }
        return left;

        // 双指针未优化
        /* int n = nums.size(), left = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                ++left;
            }
        }
        return left; */
    }
    
};
// @lc code=end

