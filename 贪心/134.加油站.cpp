/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
// 贪心算法(最优)
// On O1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] -cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};



// 贪心算法(次等)
// On O1
// class Solution{
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int curSum = 0;
//         int min = INT_MAX;
//         for (int i = 0; i < gas.size(); i++) {
//             int rest = gas[i] - cost[i];
//             curSum += rest;
//             if (curSum < min) {
//                 min = curSum;
//             }
//         }
//         if (curSum < 0) return -1;
//         if (min >= 0) return 0;
//         for (int i = gas.size() - 1; i >= 0; i--) {
//             int rest = gas[i] - cost[i];
//             min += rest;
//             if (min >= 0) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// 暴力解法
// On^2 O1
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         for (int i = 0; i < cost.size(); i++) {
//             int rest = gas[i] - cost[i];
//             int index = (i + 1) % cost.size();
//             while (rest >= 0 && index != i) {
//                 rest += gas[index] - cost[index];
//                 index = (index + 1) % cost.size();
//             }
//             if (rest >= 0 && index == i) return i;
//         }
//         return -1;
//     }
// };


// @lc code=end



