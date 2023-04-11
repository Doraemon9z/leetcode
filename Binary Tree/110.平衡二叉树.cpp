/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
// Solution class definition
class Solution {
public:
    bool ans; // boolean variable to keep track of balance status
    // function to recursively calculate the height of the binary tree
    int getHeight(TreeNode* node) {
        if (!node) return 0; // base case: empty node
        if (!ans) return 0; // if balance status is false, return 0
        int leftHeight = getHeight(node->left); // calculate height of left subtree
        int rightHeight = getHeight(node->right); // calculate height of right subtree
        if (abs(leftHeight - rightHeight) > 1) ans = false; // check balance status
        return max(leftHeight, rightHeight) + 1; // return height of current node
    }
    // function to check if binary tree is balanced
    bool isBalanced(TreeNode* root) {
        ans = true; // set balance status to true
        int temp = getHeight(root); // calculate height of binary tree
        return ans; // return balance status
    }
};

// 当然此题用迭代法，其实效率很低，因为没有很好的模拟回溯的过程，所以迭代法有很多重复的计算。
// 虽然理论上所有的递归都可以用迭代来实现，但是有的场景难度可能比较大。
// 例如：都知道回溯法其实就是递归，但是很少人用迭代的方式去实现回溯算法！
// 因为对于回溯算法已经是非常复杂的递归了，如果再用迭代的话，就是自己给自己找麻烦，效率也并不一定高。
// 所以，对于回溯算法，还是用递归来实现吧！
// 但是对于这道题，我们可以用迭代的方式来实现，只是效率不高而已。
// 这里给出迭代的实现方式：
/* class Solution {
private:
    int getDepth(TreeNode* cur) {
        stack<TreeNode*> st;
        if (cur != NULL) st.push(cur);
        int depth = 0; // 记录深度
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);
                depth++;
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }

public:
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) {
                return false;
            }
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return true;
    }
}; */
// @lc code=end

