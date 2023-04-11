/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true;
        if (!cur->left && !cur->right) return false;
        if (cur->left) {
            count -= cur->left->val;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val;
        } 
        if (cur->right) {
            count -= cur->right->val;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
};

// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) {
//         if (!root) return false;
//         if (!root->left && !root->right && sum == root->val) return true;
//         return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val); 
//     }
// };

// class solution {

// public:
//     bool haspathsum(TreeNode* root, int sum) {
//         if (root == null) return false;
//         // 此时栈里要放的是pair<节点指针，路径数值>
//         stack<pair<TreeNode*, int>> st;
//         st.push(pair<TreeNode*, int>(root, root->val));
//         while (!st.empty()) {
//             pair<TreeNode*, int> node = st.top();
//             st.pop();
//             // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
//             if (!node.first->left && !node.first->right && sum == node.second) return true;

//             // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
//             if (node.first->right) {
//                 st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
//             }

//             // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
//             if (node.first->left) {
//                 st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
//             }
//         }
//         return false;
//     }
// };
// @lc code=end

