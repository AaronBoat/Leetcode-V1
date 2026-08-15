class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int begin_back = nums.size() - k;

        vector<int> tem(k);
        vector<int> ans(begin_back);
        for (int i = begin_back; i < nums.size(); i++)
        {
            int to_index = i - (begin_back);
            tem[to_index] = nums[i];
        }
        for (int i = 0; i < begin_back; i++)
        {
            ans[i] = nums[i];
        }
        ans.insert(ans.begin(),tem.begin(),tem.end());
        nums = ans;
    }
};