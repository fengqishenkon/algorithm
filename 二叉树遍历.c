#define _CRT_SECURE_NO_WARNINGS 

//����������ʽ�ṹ
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
//�������
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
    //�����û������һ����������ַ���
    char arr[100];
    scanf("%s", arr);
    //����������
    int i = 0;
    TreeNode* root = createTree(arr, &i);
    //�������
    inOrder(root);
    return 0;

}