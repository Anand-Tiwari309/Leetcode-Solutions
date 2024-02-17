class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        vector<TreeNode*> nodes;
        preorderTraversal(root, nodes);
          TreeNode* curr=root;
          root->left=NULL;
          root->right=NULL;
        for (int i = 1; i < nodes.size(); ++i) {
            curr->left = nullptr;
            curr->right = nodes[i];
            curr = curr->right;
        }
    }

private:
    void preorderTraversal(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == nullptr)
            return;

        nodes.push_back(node);
        preorderTraversal(node->left, nodes);
        preorderTraversal(node->right, nodes);
    }
};
