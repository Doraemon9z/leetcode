/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 双指针，链表A不相交部分为a，链表B不相交部分为b，二者相交部分为c， a+b+c=a+b+c，会在相交结点相遇
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* A = headA;
        ListNode* B = headB;
        while (A != B) {
        A = A == NULL ? headB : A->next;
        B = B == NULL ? headA : B->next;
    }
    return A;
     
    }
};
// @lc code=end

