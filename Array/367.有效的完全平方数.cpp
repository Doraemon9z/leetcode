/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        // 二分查找
        int left = 0, right = num;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if ((long)mid * mid <= num ) {
                left = mid + 1;
                if ((long)mid * mid == num) {
                    return true;
                }
            } else {
                right = mid - 1;
            }
        }
        return false;
        // 暴力
        /* long x = 1, square = 1;
        while (square <= num) {
            if (square == num) {
                return true;
            }
            ++x;
            square = x * x;
        }
        return false; */



    }
};
// @lc code=end

