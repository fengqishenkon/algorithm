#define _CRT_SECURE_NO_WARNINGS 

// Linked List Cycle II

//https://leetcode.cn/problems/linked-list-cycle-ii/description/

//!!! The distance from the head node and the meeting point to the entry node of the loop is equal.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* detectCycle(struct ListNode* head)
{
    ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)//相遇点
        {
            //找入环的第一个结点
            ListNode* pcur = head;
            while (slow != pcur)
            {
                slow = slow->next;
                pcur = pcur->next;
            }
            return pcur;
        }
    }
    return NULL;
}