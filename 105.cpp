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
#include <unordered_map>
using namespace std;
class Solution
{
private:
    void build(TreeNode *root, int l_pre, int r_pre, int l_in, int r_in, const vector<int> &preorder, const vector<int> &inorder, const unordered_map<int, int> &inorder_index_val_to_index)
    {
        if (l_pre == r_pre)
        {
            return;
        }

        const int val_root = preorder[l_pre];
        const int index_in = inorder_index_val_to_index.at(val_root);
        const int len_of_leftSub = index_in - l_in;
        const int len_of_rightSub = r_in - index_in;

        
        if (len_of_leftSub > 0)
        {
        }
        else
        {
        }
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorder_index_val_to_index;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_index_val_to_index[inorder[i]] = i;
        }
    }
};