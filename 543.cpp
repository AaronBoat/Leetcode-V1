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
class Solution
{
private:
    int depth_max = -1;
    int depth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            const int l_depth = depth(l);
            const int r_depth = depth(r);
            const int depth_now = max(l_depth, r_depth) + 1;
            depth_max = max(depth_max, l_depth + r_depth + 1);
            return depth_now;
        }
    }
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            depth_max = -1;
            depth(root);
            return depth_max - 1;
            
        }
    }
};