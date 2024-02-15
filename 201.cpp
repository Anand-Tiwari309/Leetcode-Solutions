https://leetcode.com/submissions/detail/1175411409/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        return (countNodes(root->left)+countNodes(root->right)+1);
    }
};