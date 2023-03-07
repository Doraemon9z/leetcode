/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int result = INT32_MAX;
        int sum = 0, i = 0, subLength = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

