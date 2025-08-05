#define _CRT_SECURE_NO_WARNINGS 

// The structure of a linked list
 //https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa

//!!!First find the middle node, and then traverse the two linked lists on both sides.

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    //���м���
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast, * slow;
        fast = slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    //��ת�м���֮�������
    ListNode* reverseList(ListNode* mid)
    {
        if (mid == NULL)
        {
            return mid;
        }
        ListNode* n1, * n2, * n3;
        n1 = NULL;
        n2 = mid;
        n3 = n2->next;
        while (n2)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3)
            {
                n3 = n3->next;
            }
        }
        return n1;
    }
    bool chkPalindrome(ListNode* A) {
        // write code here
        //���м���
        ListNode* mid = middleNode(A);
        //��ת�м���֮�������
        ListNode* right = reverseList(mid);
        //����ԭ����ͷ�ת�������
        ListNode* left = A;
        while (right)
        {
            if (left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};