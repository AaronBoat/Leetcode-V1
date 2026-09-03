class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 1;
        long long product = nums[0];
        int ans =  (int)(nums[0] < k);
        if(nums.size() <= 1)
        {
            return (int)(nums[0] < k);
        }
        while (r < nums.size())
        {
            if(l >= r)
            {
                r = l + 1;
                //1
cout<<"l > r so move r to "<<r<<'\n';
                //2
            }
            const int p_after_add_r = product * nums[r] 
            if(p_after_add_r< k)
            {
                r++;
                ans++;
                product = p_after_add_r;
                //1
cout<<"we can add "<<nums[r]<<" because product then: "<<p_after_add_r<<'\n';
                //2
            }
            else
            {
                product /= nums[l];
                l++;
            }
        }
        return ans;
    }
};