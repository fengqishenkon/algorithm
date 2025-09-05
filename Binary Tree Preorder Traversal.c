#define _CRT_SECURE_NO_WARNINGS 

//Binary Tree Preorder Traversal

//https://leetcode.cn/problems/binary-tree-preorder-traversal/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */


typedef struct TreeNode TreeNode;
//结点总数=1+左孩子结点总数+右孩子结点总数；
int TreeSize(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void preOrder(TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    //保存根结点的值到数组中
    arr[(*pi)++] = root->val;
    preOrder(root->left, arr, pi);
    preOrder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //求树的结点个数
    *returnSize = TreeSize(root);
    //数组要申请*returnSize个int空间的大小
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    //前序遍历
    int i = 0;
    preOrder(root, arr, &i);
    return arr;
}
