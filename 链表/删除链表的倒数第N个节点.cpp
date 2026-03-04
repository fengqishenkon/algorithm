#define _CRT_SECURE_NO_WARNINGS 



//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

//删除链表的倒数第N个节点


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = nullptr;
        cur = dummyhead->next;
        while (cur->next != nullptr)
        {
            i++;
            cur = cur->next;
        }
        cur = dummyhead;
        int s = i - n + 2;
        ListNode* tmp = nullptr;
        while (s--)
        {
            tmp = cur;
            cur = cur->next;
        }
        tmp->next = cur->next;
        delete cur;
        return dummyhead->next;
    }
};


