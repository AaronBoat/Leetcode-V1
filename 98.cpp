#include <vector>
using namespace std;

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
    vector<int> zhongxu(TreeNode *root, vector<int> val_zhongxu)
    {
        if (root == nullptr)
        {
            return val_zhongxu;
        }
        zhongxu(root->left,val_zhongxu);
        val_zhongxu.push_back(root->val);
        zhongxu(root->right,val_zhongxu);
        return val_zhongxu;
    }
    bool is_up(const vector<int>& val)
    {
        for(int i = 0 ; i < val.size() - 1;i++)
        {
            if(val[i] >= val[i + 1])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        
    }
};