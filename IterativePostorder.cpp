class Solution {
public:
    void postorder_traversel(vector<int>& ans, TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
            ans.push_back(curr->val);  
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder_traversel(ans, root);
        return ans;
    }
};