#define _CRT_SECURE_NO_WARNINGS 

// Remove Linked List Elements

//https ://leetcode.cn/problems/remove-linked-list-elements/

//!!! Create a new structure pointer,Keep only the nodes that are not equal to val.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val)
{
    ListNode* newhead, * newback;
    newhead = newback = NULL;
    ListNode* ptail = head;
    while (ptail)
    {
        if (ptail->val != val)
        {
            if (newhead == NULL)
            {
                newhead = newback = ptail;
            }
            else
            {
                newback->next = ptail;
                newback = ptail;
            }

        }
        ptail = ptail->next;
    }
    if (newback != NULL)
    {
        newback->next = NULL;
    }
    return newhead;
}