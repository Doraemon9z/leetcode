/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        // 用链表插入，效率更高
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) it++;
            que.insert(it, people[i]);
        }
        return vector<vector<int>> (que.begin(), que.end());

        // 使用vector是非常费时的，因为每次插入都要移动后面的元素
        // vector<vector<int>> que;
        // for (int i = 0; i < people.size(); i++) {
        //     int position = people[i][1];
        //     que.insert(que.begin() + position, people[i]);
        // }
        // return que;
    }
};
// @lc code=end

