class Solution
{
private:
    void PrintLog(int i)
    {
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() < 1)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }
        assert(nums.size() > 1);
        int max_sum = nums[0];
        int min_sum = min(nums[0], 0);
        int max_diff = -2e5;
        long long pre_sum = 0;
        // vector<int> preSum(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];
            max_sum = max_sum >= pre_sum ? max_sum : pre_sum;
            max_diff = std::max(max_diff, max_sum - min_sum);
            min_sum = min_sum <= pre_sum ? min_sum : pre_sum;
            //
            cout << "now at round " << i << " ";
            cout << "max: "<<max_sum << " min: "<<min_sum<<" diff: "<<max_diff<<endl;
            ///
        }
        return max_diff;
    }
};