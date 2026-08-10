class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = -2e4;
        int min_sum = 2e4;
        long long pre_sum = 0;
        // vector<int> preSum(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];
            max_sum = max_sum >= pre_sum ? max_sum : pre_sum;
            min_sum = min_sum <= pre_sum ? min_sum : pre_sum;
        }
        return max_sum - min_sum;
    }
};