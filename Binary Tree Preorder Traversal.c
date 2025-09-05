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
//�������=1+���ӽ������+�Һ��ӽ��������
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
    //���������ֵ��������
    arr[(*pi)++] = root->val;
    preOrder(root->left, arr, pi);
    preOrder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //�����Ľ�����
    *returnSize = TreeSize(root);
    //����Ҫ����*returnSize��int�ռ�Ĵ�С
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    //ǰ�����
    int i = 0;
    preOrder(root, arr, &i);
    return arr;
}
