/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 双指针法
        int k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j; ) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[k--] = nums[j] * nums[j];
                --j;
            }
            else {
                result[k--] = nums[i] * nums[i];
                ++i;
            }
        }
        return result;



        // 暴力排序
        /* for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums; */
    }
};
// @lc code=end

