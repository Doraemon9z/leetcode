/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxCount = 0;
    int count = 0;
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return;
        searchBST(cur->left);
        if (pre == NULL) {
            count = 1;
        } else if (pre->val == cur->val) {
            count++;
        } else {
            count = 1;
        }
        pre = cur;

        if (count == maxCount) {
            result.push_back(cur->val);
        }
        if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        searchBST(cur->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = NULL;
        result.clear();
        searchBST(root);
        return result;
    }
};


//  如果不是二叉搜索树，那么就需要用到哈希表来存储每个节点的值和出现的次数，然后遍历哈希表，找到出现次数最多的节点值，将其放入结果数组中即可。
// class Solution {
// private:
//     void searchBST(TreeNode* cur, unordered_map<int, int>& map) {
//         if (!cur) return;
//         map[cur->val]++;
//         searchBST(cur->left, map);
//         searchBST(cur->right, map);
//         return;
//     }

//     bool static cmp(const pair<int< int>& a, const pair<int, int>& b) {
//         return a.second > b.second;
//     }
// public:
//     vector<int> findMode(TreeNode* root) {
//         unordered_map<int, int> map;
//         vector<int> result;
//         if (!root) return result;
//         searchBST(root, map);
//         vector<pair<int, int>> vec(map.begin(), map.end());
//         sort(vec.begin(), vec.end(), cmp);
//         result.push_back(vec[0].first);
//         for (int i = 1; i < vec.size(); i++) {
//             if (vec[i].second == vec[0].second) {
//                 result.push_back(vec[i].first);
                
//             }
//             else break;
//         }
//         return result;
//     }
// };
// @lc code=end

