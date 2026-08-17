#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<TreeNode *> BFS;
        vector<vector<int>> ans;
        BFS.reserve(2e4);
        BFS.push_back(root);

        int head = 0;
        while (BFS.size() - head > 0)
        {
            int size_level_now = BFS.size() - head;
            // int end = BFS.size();
            vector<int> val_level_now(size_level_now);
            for (int delta = 0; delta < size_level_now; delta++)
            {
                TreeNode *node_now = BFS[head + delta];
                val_level_now[delta] = node_now;

                if (node_now->left != nullptr)
                {
                    BFS.push_back(node_now->left);
                }
                if (node_now->right != nullptr)
                {
                    BFS.push_back(node_now->right);
                }
            }
            head += size_level_now;
            ans.push_back(val_level_now);
        }
        return ans;
    }
};