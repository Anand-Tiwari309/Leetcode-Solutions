https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
public:
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        markParents(root, mp, target);

        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, k});

        vector<int> ans;

        while (!q.empty()) {
            TreeNode* new_node = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (distance == 0) {
                ans.push_back(new_node->val);
            }

            visited[new_node] = true;

            if (new_node->left && !visited[new_node->left]) {
                q.push({new_node->left, distance - 1});
            }

            if (new_node->right && !visited[new_node->right]) {
                q.push({new_node->right, distance - 1});
            }

            if (mp.find(new_node) != mp.end() && !visited[mp[new_node]]) {
                q.push({mp[new_node], distance - 1});
            }
        }

        return ans;
    }
};
