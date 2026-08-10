class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if(nums.size() < 1)
        {
            return 0;
        }
        assert(nums.size() >= 1)
        int max_sum = nums[0];
        int min_sum = nums[0];
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