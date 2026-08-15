#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        constexpr int number_range = 1e5 + 5;
        vector<bool> is_exist(number_range);

        for(auto it: nums)
        {
            if(it >= 0 && it < number_range)
            {
                is_exist[it] = true;
            }
        }

        for(int i = 1 ; i < number_range ; i++)
        {
            if(!is_exist[i])
            {
                return i;
            }
        }

        return -1;
    }
};