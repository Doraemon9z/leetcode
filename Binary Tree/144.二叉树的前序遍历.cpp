/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    /* void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    } */

    vector<int> preorderTraversal(TreeNode* root) {
        // 统一迭代
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;

        
        
        // 迭代
        /* stack<TreeNode*> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result; */




        // 递归
        /* vector<int> result;
        traversal(root, result);
        return result; */
    }
};
// @lc code=end

