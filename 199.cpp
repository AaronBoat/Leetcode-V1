/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;
class Solution
{
private:
    constexpr int MAX_DEPTH = 100 + 5;
    void walk_tree(TreeNode *root, vector<bool> &visited, int depth, vector<int> ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (!visited[depth])
        {
            ans.push_back(root->val);
            visited[depth] = true;
        }
        walk_tree(root->right, visited, depth + 1, ans);
        walk_tree(root->left, visited, depth + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<bool> visited(MAX_DEPTH,false);
        vector<int> ans;
        walk_tree(root,visited,0,ans);
        return ans;
    }
};