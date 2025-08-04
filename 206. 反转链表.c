#define _CRT_SECURE_NO_WARNINGS 
//反转链表
//https://leetcode.cn/problems/reverse-linked-list/description/
//！！三指针法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return head;
	}
	ListNode* n1 = NULL;
	ListNode* n2 = head;
	ListNode* n3 = n2->next;
	while (n2 != NULL)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	return n1;
}
