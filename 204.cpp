https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    where 'N' is the number of nodes in the tree.
    
*/

#include <unordered_map>

void inorder(BinaryTreeNode<int> *root, unordered_map<int, vector<int>> &m)
{
    if (root)
    {
        if (root->left)
        {
            m[root->data].push_back(root->left->data);
            m[root->left->data].push_back(root->data);
        }
        if (root->right)
        {
            m[root->data].push_back(root->right->data);
            m[root->right->data].push_back(root->data);
        }
        inorder(root->left, m);
        inorder(root->right, m);
    }
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    unordered_map<int, vector<int>> m;
    
    inorder(root, m);
    
    queue<int> q;
    
    q.push(start);
    
    int count = 0;
    unordered_map<int, bool> visited;
    visited[start] = true;
    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            q.pop();
            
            for(auto i:m[node])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    
    return count - 1;
}
