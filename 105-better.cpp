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
struct TreeNode
{
};
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
private:
    unordered_map<int, int> inorder_index_val_to_index;
    TreeNode *build(vector<int> &preorder, int val_root, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        const int index_in = inorder_index_val_to_index[val_root];
        TreeNode *root = new TreeNode(val_root);
        const int len_l = index_in - l;
        root->left = build(preorder, preorder[l + 1], l + 1, index_in - 1);
        root->right = build(preorder, preorder[index_in + 1], index_in + 1, r);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_index_val_to_index[inorder[i]] = i;
        }
        return build(preorder, preorder[0], 0, preorder.size() - 1)
    }
};