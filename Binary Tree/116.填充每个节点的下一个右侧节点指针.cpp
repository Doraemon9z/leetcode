/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// This code is a solution to the problem of connecting nodes at the same level in a binary tree.
// The function takes in a root node and returns the same root node with the next pointers set to the next node at the same level.
class Solution {
public:
    Node* connect(Node* root) {
        // Create a queue to store the nodes at each level.
        queue<Node*> que;
        // If the root is not null, add it to the queue.
        if (root != NULL) que.push(root);
        // While the queue is not empty, process the nodes at each level.
        while (!que.empty()) {
            // Get the number of nodes at the current level.
            int size = que.size();
            // Initialize the previous and current nodes.
            Node* nodePre;
            Node* node;
            // Process each node at the current level.
            for (int i = 0; i < size; i++) {
                // If this is the first node at the level, set the previous and current nodes to it.
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                } else {
                    // If this is not the first node, set the current node to the front of the queue and set the previous node's next pointer to it.
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }
                // Add the left and right children of the current node to the queue.
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            // Set the next pointer of the last node at the level to null.
            nodePre->next = NULL;  
        }
        // Return the root node with the next pointers set.
        return root;
    }
};

// @lc code=end

