/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
        if (left > right) return NULL;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};

// 迭代
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if (nums.size() == 0) return NULL;
//         TreeNode* root = new TreeNode(0);
//         queue<TreeNode*> nodeQue;
//         queue<int> leftQue, rightQue;
//         nodeQue.push(root);
//         leftQue.push(0);
//         rightQue.push(nums.size() - 1);
        
//         while (!nodeQue.empty()) {
//             TreeNode* curNode = nodeQue.front();
//             nodeQue.pop();
//             int left = leftQue.front();
//             leftQue.pop();
//             int right = rightQue.front();
//             rightQue.pop();
//             int mid = left + ((right-left) >> 1);
                       
//             curNode->val = nums[mid];

//             if (left <= mid - 1) {
//                 curNode->left = new TreeNode(0);
//                 nodeQue.push(curNode->left);
//                 leftQue.push(left);
//                 rightQue.push(mid - 1);
//             }

//             if (right >= mid  + 1) {
//                 curNode->right = new TreeNode(0);
//                 nodeQue.push(curNode->right);
//                 leftQue.push(mid + 1);
//                 rightQue.push(right);
//             }
//         }
//         return root;
//     }
// };
// @lc code=end

