/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) {
            result = min(result, vec[i] - vec[i - 1]);
        }
        return result;
    }
};


// 双指针
// class Solution {
// private:
// int result = INT_MAX;
// TreeNode* pre = NULL;
// void traversal(TreeNode* cur) {
//     if (cur == NULL) return;
//     traversal(cur->left);   // 左
//     if (pre != NULL){       // 中
//         result = min(result, cur->val - pre->val);
//     }
//     pre = cur; // 记录前一个
//     traversal(cur->right);  // 右
// }
// public:
//     int getMinimumDifference(TreeNode* root) {
//         traversal(root);
//         return result;
//     }
// };
// @lc code=end

