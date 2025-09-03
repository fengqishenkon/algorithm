#define _CRT_SECURE_NO_WARNINGS 

// Subtree of Another Tree

//https://leetcode.cn/problems/subtree-of-another-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    //��Ϊ�շ���true
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //��һ��Ϊ��
    if (p == NULL || q == NULL)
    {
        return false;
    }

    //����Ϊ��
    if (p->val != q->val)
    {
        return false;
    }
    //�Ƚ���һ�����

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
    {
        return false;
    }
    if (isSameTree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}