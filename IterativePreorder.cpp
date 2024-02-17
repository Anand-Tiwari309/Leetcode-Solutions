class Solution {
public:
    void preorder_traversal(vector<int>& ans, TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                ans.push_back(curr->val);  // Corrected line
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder_traversal(ans, root);
        return ans;
    }
};
