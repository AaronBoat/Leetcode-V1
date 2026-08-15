class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> pre_pro(nums.size());
        vector<int> suf_pro(nums.size());

        pre_pro[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre_pro[i] = pro_pro[i - 1] * nums[i];
        }

        int back = nums.size() - 1 suf_pro[back] = nums[back];
        for (int i = back - 1; i >= 0; i--)
        {
            suf_pro[i] = suf_pro[i + 1] * nums[i];
        }

        vector ans(nums.size());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int left_pro = 1;
            if(i >= 1)
            {
                left_pro = pre_pro[i - 1];
            }
            int right_pro = 1;
            if(i <= back - 1)
            {
                right_pro = suf_pro[i + 1];
            }

            ans[i] = left_pro * right_pro;
        }
    }
};