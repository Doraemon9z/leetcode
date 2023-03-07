/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 排序 + 双指针
        // 时间复杂度：O(n^3)，其中 n 是数组的长度。排序的时间复杂度是 O(nlog⁡n)，枚举四元组的时间复杂度是 O(n^3)，
        // // 因此总时间复杂度为 O(n^3+nlog⁡n)=O(n^3) 
        // 空间复杂度：O(log⁡n)，其中 n 是数组的长度。空间复杂度主要取决于排序额外使用的空间。此外排序修改了输入数组 nums，
        // 实际情况中不一定允许，因此也可以看成使用了一个额外的数组存储了数组 nums 的副本并排序，空间复杂度为 O(n)。

        vector<vector<int>> ans;
        if (nums.size() < 4 ) {
            return ans;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int first = 0; first < n - 3; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            if ((long) nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) {
                break;
            }
            if ((long) nums[first] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }

            for (int second = first + 1; second < n - 2; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                if ((long) nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) {
                    break;
                }
                if ((long) nums[first] + nums[second] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                
                int third = second + 1;
                int fourth = n - 1;

                while (third < fourth) {
                    long sum = (long) nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) {
                        ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        while (third < fourth && nums[third] == nums[third + 1]) {
                            ++third;
                        }
                        ++third;
                        while (third < fourth && nums[fourth] == nums[fourth - 1]) {
                            --fourth;
                        }
                        --fourth;
                    } else if (sum < target) {
                        ++third;
                    } else {
                        --fourth;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

