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
    inline vector<int> sub_vector(const vector<int> &vec, const int &begin, const int &end)
    {
        assert(end >= begin);
        vector<int> sub_v(end - begin);
        for (int delta = 0; delta < end - begin; delta++)
        {
            sub_v[delta] = vec[begin + delta];
        }
        return sub_v;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        const int mid_index = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid_index]);
        vector<int> left_vec = sub_vector(nums, 0, mid_index);
        root->left = sortedArrayToBST(left_vec);
        vector<int> right_vec = sub_vector(nums,mid_index+1,nums.size());
        root->right = sortedArrayToBST(right_vec);
        return root;
    }
};