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
#include <cmath>
#include <algorithm>
#include <climits>
class Solution
{
private:
    int ans = std::numeric_limits<int>::min();
    int max_path(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        const int val = root->val;
        const int left_sub_path_max = max_path(root->left);
        const int right_sub_path_max = max_path(root->right);
        ans = max(ans, max(max(left_sub_path_max + right_sub_path_max + val,val),max(val+left_sub_path_max,val+right_sub_path_max)));
        //1
//cout << " at pos: "<<val<<"with left and right: "<<left_sub_path_max<<" , "<<right_sub_path_max<<'\n';
        //2
        return max(val,max(val+left_sub_path_max,val+right_sub_path_max));
    }

public:
    int maxPathSum(TreeNode *root)
    {
        ans = std::numeric_limits<int>::min();
        max_path(root);
        return ans;
    }
};