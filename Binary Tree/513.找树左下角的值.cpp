/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    // 递归
    /* int maxDepth =  INT_MIN;
    int result;
    void traversal(TreeNode* root, int depth) {
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left) {
            depth++;
            traversal(root->left, depth);
            depth--;
            // traversal(root->left, depth + 1);
        }
        if (root->right) {
            depth++;
            traversal(root->right, depth);
            depth--;
            // traversal(root->right, depth + 1);
        }
        return;
    } */


    int findBottomLeftValue(TreeNode* root) {
        //  层序遍历 找最底一层的第一个节点
        queue<TreeNode*> que;
        if (root) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
        
        //  递归
        /* traversal(root, 0);
        return result; */
    }
};
// @lc code=end

