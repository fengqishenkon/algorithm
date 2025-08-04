#define _CRT_SECURE_NO_WARNINGS 

//middle of the linked list

// https ://leetcode.cn/problems/middle-of-the-linked-list/

//!! Fast - Slow Pointer Method

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}