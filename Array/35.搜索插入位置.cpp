/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分查找
        int left = 0, right = (int)nums.size() - 1, ans = nums.size();
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

