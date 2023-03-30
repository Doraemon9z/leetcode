/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
private:
    class MyQueue {
        public:
            deque<int> que;
            void pop(int value) {
                if (!que.empty() && value == que.front()) {
                    que.pop_front();
                }
            }

            void push(int value) {
                while (!que.empty() && value > que.back()) {
                    que.pop_back();
                }
                que.push_back(value);
            }

            int front() {
                return que.front();
            }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;

        // leetcode 官方题解
        /* int n = nums.size();
        vector<int>prefixMax(n), suffixMax(n);
        for (int i = 0; i < n; ++i) {
            if (i % k == 0) {
                prefixMax[i] = nums[i];
            }
            else {
                prefixMax[i] = max(prefixMax[i - 1],nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || (i + 1) % k == 0) {
                suffixMax[i] = nums[i];
            }
            else {
                suffixMax[i] = max(suffixMax[i + 1],nums[i]);
            }
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            ans.push_back(max(suffixMax[i],prefixMax[i + k - 1]));
        }
        return ans; */

    }
};
// @lc code=end

