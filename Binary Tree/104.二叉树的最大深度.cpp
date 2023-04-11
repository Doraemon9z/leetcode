/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // 前序(简化)
    /* int result;
    void getdepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result;
        if (node->left == NULL && node->right == NULL) return;
        if (node->left) {
            getdepth(node->left, depth + 1);
        }
        if (node->right) {
            getdepth(node->right, depth + 1);
        }
        return;
    } */

    // 前序(未简化)
    /* int result;
    void getdepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result;
        if (node->left == NULL && node->right == NULL) return;
        if (node->left) {
            depth++;
            getdepth(node->left, depth);
            depth--;
        }
        if (node->right) {
            depth++;
            getdepth(node->right, depth);
            depth--;
        }
        return;
    } */

    // 递归
    /* int getdepth(TreeNode* root) {
        if (root ==nullptr) return 0;
        int left = getdepth(root->left);
        int right = getdepth(root->right);
        int depth = max(left, right) + 1;
        return depth;
    } */

    int maxDepth(TreeNode* root) {  
        // 迭代
        if (root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++; // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
        
        // 前序
        /* result = 0
        if (root == NULL) return result;
        getdepth(root, 1);
        return result; */
        
        // 递归(代码精简)
        /* if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); */

        // 递归(代码未精简)
        /* return getdepth(root); */
    }
};
// @lc code=end

