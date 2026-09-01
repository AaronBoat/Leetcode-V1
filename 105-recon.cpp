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
#include <assert.h>
using namespace std;
class Solution
{

private:
    unordered_map<int, int> inorder_index_val_to_index;

    TreeNode *dg(vector<int> &preorder, int pre_l, int pre_r, int z_l, int z_r)
    {
        if (pre_l > pre_r)
        {
            return nullptr;
        }
        assert(pre_r - pre_l == z_r - z_l);
        const int val_root = preorder[pre_l];
        const int index_z = index_inorder[val_root];
        const int delta_leftSub = index_z - z_l;
        const int delta_rightSub = z_r - index_z;
        TreeNode *root = new TreeNode(val_root);
        root->left = dg(preorder, pre_l + 1, pre_l + 1 + delta_leftSub, z_l, z_l + delta_leftSub);
        root->right = dg(preorder, pre_r - delta_rightSub, pre_r, index_z + 1, z_r);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_index_val_to_index[inorder[i]] = i;
        }
        return dg(preorder,0,preorder.size(),0,inorder.size());
    }
};