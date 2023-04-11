/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;
        int maxValueIndex = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }
        TreeNode* root = new TreeNode(nums[maxValueIndex]);
        root->left = traversal(nums, left, maxValueIndex);
        root->right = traversal(nums, maxValueIndex + 1, right);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};


//  未优化
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         TreeNode* node = new TreeNode(0);
//         if (nums.size() == 1) {
//             node->val = nums[0];
//             return node;
//         }      
//         int maxValue = 0;
//         int maxValueIndex = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > maxValue) {
//                 maxValue = nums[i];
//                 maxValueIndex = i;
//             }
//         }
//         node->val = maxValue;
//         if (maxValueIndex > 0) {
//             vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
//             node->left = constructMaximumBinaryTree(newVec);
//         }
//         if (maxValueIndex < (nums.size() - 1)) {
//             vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
//             node->right = constructMaximumBinaryTree(newVec);
//         }
//         return node;
//     }
// };
// @lc code=end

