class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        assert(k <= nums.size());
        vector<int> ans;

        if (k == 1)
        {
            ans = nums;
        }
        else
        {
            deque<int> d_index;

            for (int i = 0; i < nums.size(); i++)
            {
                const int val_new = nums[i];
                for (int j = d_index.size() - 1; j >= 0; j--)
                {
                    if (nums[d_index[j]] > val_new) // TOd_indexO 等于要不要删除
                    {
                        break;
                    }
                    else
                    {
                        d_index.pop_back();
                    }
                }
                d_index.push_back(i);

                if (d_index.front() < i - k + 1)
                {
                    d_index.pop_front();
                }

                if (i >= k - 1)
                {
                    assert(!d_index.empty());
                    ans.push_back(nums[d_index.front()]);
                }
            }
        }
        return ans;
    }
};