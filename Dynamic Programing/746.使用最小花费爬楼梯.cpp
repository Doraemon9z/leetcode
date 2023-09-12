/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 还可以优化空间复杂度
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int dpi = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
            dp0 = dp1;
            dp1 = dpi;
        }
        return dp1;
        
        // vector<int> dp(cost.size() + 1);
        // dp[0] = 0;
        // dp[1] = 0;
        // for (int i = 2; i <= cost.size(); i++) {
        //     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        // }
        // return dp[cost.size()];
    }
};
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> dp(cost.size());
//         dp[0] = cost[0]; // 第一步有花费
//         dp[1] = cost[1];
//         for (int i = 2; i < cost.size(); i++) {
//             dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//         }
//         // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
//         return min(dp[cost.size() - 1], dp[cost.size() - 2]);
//     }
// };
// @lc code=end

