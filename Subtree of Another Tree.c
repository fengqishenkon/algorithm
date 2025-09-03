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
    //都为空返回true
    if (p == NULL && q == NULL)
    {
        return true;
    }

    //有一个为空
    if (p == NULL || q == NULL)
    {
        return false;
    }

    //都不为空
    if (p->val != q->val)
    {
        return false;
    }
    //比较下一个结点

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