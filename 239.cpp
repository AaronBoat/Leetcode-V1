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
            deque<int> d;

            for (int i = 0; i < nums.size(); i++)
            {
                const int val_new = nums[i];
                for (int j = d.size() - 1; j >= 0; j--)
                {
                    if (nums[d[j]] > val_new) // TODO 等于要不要删除
                    {
                        break;
                    }
                    else
                    {
                        d.pop_back();
                    }
                }
                d.push_back(val_new);

                if (d.front() < i - k + 1)
                {
                    d.pop_front();
                }

                if (i >= k - 1)
                {
                    assert(!d.empty());
                    ans.push_back(nums[d.front()]);
                }
            }
        }
        return ans;
    }
};