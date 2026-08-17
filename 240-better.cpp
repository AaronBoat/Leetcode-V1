#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // bool ans = false;
        const int size_row = matrix.size();
        const int size_col = matrix[0].size();

        int x = 0, y = size_col - 1;
        // auto is_valid = [&](int location, int range_up)
        // {
        //     return location >= 0 && location <= range_up;
        // };
        while (x < size_row && y >= 0)
        {
            const int val = matrix[x][y];
            if (val == target)
            {
                return true;
            }
            else if (val > target)
            {
                y--;
            }
            else if (val < target)
            {
                x++;
            }
        }
        return false;
    }
};