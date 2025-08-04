#define _CRT_SECURE_NO_WARNINGS 

//Merge Two Sorted Lists
//https://leetcode.cn/problems/merge-two-sorted-lists/submissions/649795163/

//!!！creating a new head node method

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    ListNode* l1, * l2;
    l1 = list1;
    l2 = list2;
    ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newtail = newhead;
    /*ListNode* newhead = NULL;
    ListNode* newtail = NULL;*/
    
    //链表为空就返回非空的那个链表，要是都为空，返回的那个也为空
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            //l2尾插到新链表中        
                newtail->next = l2;
                newtail = newtail->next;
                l2 = l2->next;    
        }
        else
        {
            //l1尾插到新链表中                    
                newtail->next = l1;
                newtail = newtail->next;
                l1 = l1->next;
        }
    }

    //判断谁先为遍历完，把没遍历完的直接接到新链表后面
    if (l1 == NULL)
    {
        newtail->next = l2;
        l2 = l2->next;
    }
    else
    {
        newtail->next = l1;
        l1 = l1->next;
    }
    ListNode* rethead= newhead->next;
    free(newhead);
    newhead == NULL;
    return rethead;
}
