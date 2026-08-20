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
    void zhongxu(TreeNode *root, vector<int> &kth, const int &k)
    {
        if (root == nullptr)
        {
            return;
        }
        if (kth.size() < k)
        {
            zhongxu(root->left, kth, k);
            kth.push_back(root->val);
            zhongxu(root->right, kth, k);
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> kth;
        zhongxu(root, kth, k);
        return kth.back();
    }
};