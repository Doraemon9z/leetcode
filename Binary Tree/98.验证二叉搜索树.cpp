/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        vec.clear();
        traversal(root);
        for(int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i -1]) return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     TreeNode* pre = NULL;
//     bool isValidBST(TreeNode* root) {
//         if (!root) return true;
//         bool left = isValieBST(root->left);
//         if (pre && pre->val >= root->val) return false;
//         pre = root;
//         bool right = isValieBST(root->right);
//         return left && right; 
//     }
// };

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         stack<TreeNode*> st;
//         TreeNode* cur = root;
//         TreeNode* pre = NULL;
//         while (cur || !st.empty()) {
//             if (cur) {
//                 st.push(cur);
//                 cur = cur->left;
//             } else {
//                 cur = st.top();
//                 st.pop();
//                 if (pre && cur->val <= pre->val) {
//                     return false;
//                 }
//                 pre = cur;
//                 cur = cur->right;
//             }
//         }
//         return true;
//     }
// };
// @lc code=end

