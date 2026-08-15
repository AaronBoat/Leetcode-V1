#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i = 0 ; i < nums.size() ; i ++)
        {
            while(nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1],nums[i]);
            }
        }

        for(int i = 1 ; i<nums.size() + 1;i++)
        {
            if(nums[i-1] != i)
            {
                return i;
            }
        }
        return nums.size() + 1;
    }
};