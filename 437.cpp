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
    int ans = 0;
    void dfs(unordered_map<int, int> &count_sum, TreeNode *root, int target, int last_sum)
    {
        if (root == nullptr)
        {
            return ;
        }
        const int sum = last_sum + root->val;
        count_sum[sum]++;
        const int need_sum = target - sum;

        ans += count_sum[need_sum];
        dfs(count_sum, root->left, target, sum);
        dfs(count_sum, root->right, target, sum);

        count_sum[sum]--;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        ans = 0;
        unordered_map<int,int> count_sum;
        dfs(count_sum,root,targetSum,0);
        return ans;
    }
};