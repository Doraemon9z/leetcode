/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // Recursive implementation of binary tree breadth-first traversal
    /* void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
        // If the current node is NULL, return
        if (cur == NULL) return;
        // If the size of the result vector is equal to the current depth, add a new empty vector to the result vector
        if (result.size() == depth) {
            result.push_back(vector<int>());
        }
        // Add the value of the current node to the vector at the current depth in the result vector
        result[depth].push_back(cur->val);
        // Recursively call the order function on the left and right children of the current node with the depth incremented by 1
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    } */

    vector<vector<int>> levelOrder(TreeNode* root) {
        // Queue implementation of binary tree breadth-first traversal
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }
        vector<vector<int>> result;
        // While loop to traverse the binary tree
        while (!que.empty()) {
            int size = que.size();
            // Vector to store the traversal results of the current level
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                // Get the front node of the queue
                TreeNode* node = que.front();
                que.pop();
                // Add the value of the front node to the vector
                vec.push_back(node->val);
                // If the front node has a left child, add it to the queue
                if (node->left) {
                    que.push(node->left);
                }
                // If the front node has a right child, add it to the queue
                if (node->right) {
                    que.push(node->right);
                }
            }
            result.push_back(vec);
        // Return the traversal results of all levels of the binary tree   
    }
        return result;

        // Recursive implementation of binary tree breadth-first traversal
        /* vector<vector<int>> result;
        int depth = 0;
        // Call the order function with the root node, an empty result vector, and a depth of 0
        order(root, result, depth);
        // Return the result vector
        return result; */
    }
};
// @lc code=end

