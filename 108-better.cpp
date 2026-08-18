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
    TreeNode *buildBST(vector<int> &nums, const int &left, const int &right)
    {
        if (left == right)
        {
            return nullptr;
        }
        else
        {
            const int mid_index = (left + right) / 2;
            TreeNode *root = new TreeNode(nums[mid_index]);
            root->left = buildBST(nums, left, mid_index);
            root->right = buildBST(nums, mid_index + 1, right);
            return root;
        }
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        // const int mid_index = nums.size() / 2;
        // TreeNode *root = new TreeNode(nums[mid_index]);

        return buildBST(nums,0,nums.size());
    }
};