#define _CRT_SECURE_NO_WARNINGS 

//¶þ²æÊ÷µÄÖ±¾¶

//https://leetcode.cn/problems/diameter-of-binary-tree/description/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;

        function<int(TreeNode*)> depth = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int leftDepth = depth(node->left);
            int rightDepth = depth(node->right);

            maxDiameter = max(maxDiameter, leftDepth + rightDepth);

            return max(leftDepth, rightDepth) + 1;
        };

        depth(root);
        return maxDiameter;
    }
};
