class Solution {
public:
    unordered_map<int, int> inorder_index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorder_index[inorder[i]] = i;
        }
        int preStart = 0, preEnd = preorder.size() - 1, inStart = 0;
        return build(preorder, preStart, preEnd, inStart);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, int inStart) {
        if (preStart > preEnd) return nullptr;
        
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        
        int inIndex = inorder_index[rootValue];
        int leftSubtreeSize = inIndex - inStart;
        
        root->left = build(preorder, preStart + 1, preStart + leftSubtreeSize, inStart);
        root->right = build(preorder, preStart + leftSubtreeSize + 1, preEnd, inIndex + 1);
        
        return root;
    }
};
