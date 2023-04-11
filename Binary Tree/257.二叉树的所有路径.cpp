/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        // 精简
        path += to_string(cur->val);
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result);
        if (cur->right) traversal(cur->right, path + "->", result);
        
        
        // 未精简
        /* path.push_back(cur->val); 
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();
        } */
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        // 未精简  
        // vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};

//版本二
// class Solution {
// private:
//     void traversal(TreeNode* cur, string path, vector<string>& result) {
//         path += to_string(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中
//         if (cur->left == NULL && cur->right == NULL) {
//             result.push_back(path);
//             return;
//         }
//         if (cur->left) {
//             path += "->";
//             traversal(cur->left, path, result); // 左
//             path.pop_back(); // 回溯 '>'
//             path.pop_back(); // 回溯 '-'
//         }
//         if (cur->right) {
//             path += "->";
//             traversal(cur->right, path, result); // 右
//             path.pop_back(); // 回溯'>'
//             path.pop_back(); // 回溯 '-'
//         }
//     }

// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> result;
//         string path;
//         if (root == NULL) return result;
//         traversal(root, path, result);
//         return result;

//     }
// };



// @lc code=end

