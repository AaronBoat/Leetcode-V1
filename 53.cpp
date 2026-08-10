class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if(nums.size() < 1)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        assert(nums.size() > 1);
        int min_sum = 0 ;
        int max_diff = -2e5;
        int pre_sum = 0;
        // vector<int> preSum(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];
            max_diff = max(max_diff , pre_sum - min_sum);
            min_sum = min_sum <= pre_sum ? min_sum : pre_sum;
        }
        return max_diff;
    }
};