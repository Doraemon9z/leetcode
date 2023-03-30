/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        // 关于为什么lhs和rhs前面要加个&
        // 在这个函数中，lhs 和 rhs 都是 pair<int, int> 类型的对象，
        // 它们的第二个元素是出现次数。由于 lhs 和 rhs 都是对象，因此在函数调用时会进行复制构造，这会带来一定的开销。
        // 为了避免这种开销，我们可以将 lhs 和 rhs 定义为 const pair<int, int>& 类型的引用，这样就可以避免复制构造了。
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }        
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
// @lc code=end

