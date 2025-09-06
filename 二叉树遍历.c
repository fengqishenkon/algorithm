#define _CRT_SECURE_NO_WARNINGS 

//二叉树的链式结构
#include<stdio.h>
typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* buyNode(char ch)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL)
    {
        printf("malloc is fail!");
        exit(1);
    }
    node->data = ch;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* createTree(char* arr, int* pi)
{
    if (arr[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    TreeNode* root = buyNode(arr[*pi]);
    (*pi)++;
    root->left = createTree(arr, pi);
    root->right = createTree(arr, pi);
    return root;
}
//中序遍历
void inOrder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

int main()
{
    //读入用户输入的一串先序遍历字符串
    char arr[100];
    scanf("%s", arr);
    //建立二叉树
    int i = 0;
    TreeNode* root = createTree(arr, &i);
    //中序遍历
    inOrder(root);
    return 0;

}