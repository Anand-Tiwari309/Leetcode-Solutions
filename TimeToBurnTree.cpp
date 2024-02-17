#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();

            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    int timeToBurn(TreeNode* root, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        int time = 0;


        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current->left && visited.find(current->left) == visited.end()) {
                    queue.push(current->left);
                    visited.insert(current->left);
                }
                if (current->right && visited.find(current->right) == visited.end()) {
                    queue.push(current->right);
                    visited.insert(current->right);
                }
                if (parent_track[current] && visited.find(parent_track[current]) == visited.end()) {
                    queue.push(parent_track[current]);
                    visited.insert(parent_track[current]);
                }
            }
            if (!queue.empty()) {
                time++;
            }
        }

        return time;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    Solution solution;
    TreeNode* target = root->left;

    int totalTime = solution.timeToBurn(root, target);

    cout << "Total time to burn all nodes from target node " << target->val << ": " << totalTime << " units" << endl;

    return 0;
}