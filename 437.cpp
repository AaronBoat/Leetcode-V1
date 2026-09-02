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
        //1
        cout<<"at val-"<<root->val<<" add sum: "<<sum<<"\n";
        //2
        const int need_sum = sum - target;

        ans += count_sum[need_sum];
        //1
cout<<"search for "<<need_sum<<" add "<<count_sum[need_sum]<<'\n';
        //2
        dfs(count_sum, root->left, target, sum);
        dfs(count_sum, root->right, target, sum);

        count_sum[sum]--;
        //1
        cout<<"at val-"<<root->val<<" delete sum: "<<sum<<"\n";
        //2
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        ans = 0;
        unordered_map<int,int> count_sum;
        count_sum[0] = 1;
        dfs(count_sum,root,targetSum,0);
        return ans;
    }
};