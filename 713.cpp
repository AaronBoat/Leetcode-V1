#include <iostream>
using namespace std;
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
            const int p_after_add_r = product * nums[r] ;
            if(p_after_add_r< k)
            {
                //1
cout<<"now l , r: "<<l<<" , " <<r<<" we can add "<<nums[r]<<" because product then: "<<p_after_add_r<<'\n';
                //2
                r++;
                ans++;
                product = p_after_add_r;
            }
            else
            {
                product /= nums[l];
                //1
cout<<"now l , r: "<<l<<" , " <<r<<" we delete "<<nums[l]<<" because product then: "<<product<<'\n';
                //2
                l++;
                if(product < k)
                ans+= r - l;
            }
        }
        return ans;
    }
};