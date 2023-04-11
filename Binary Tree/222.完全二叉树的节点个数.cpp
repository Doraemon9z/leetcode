/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
public:
    int countNodes(TreeNode* root) {
        // 迭代
        if (root == NULL) return 0;
        queue<TreeNode*> que;
        int result = 0;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                result++;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;

        
        // 递归
        /* if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right); */
    }
};
// @lc code=end

