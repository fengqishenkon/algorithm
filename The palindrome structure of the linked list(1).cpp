#define _CRT_SECURE_NO_WARNINGS 

//The palindrome structure of the linked list

//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa

//!!!opportunistic method

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        int arr[900] = { 0 };
        int i = 0;
        ListNode* pcur = A;
        while (pcur)
        {
            arr[i++] = pcur->val;
            pcur = pcur->next;
        }
        int left = 0;
        int right = i - 1;
        while (left < right)
        {
            if (arr[left] == arr[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};