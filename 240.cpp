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
        for (int i = 0; i < size_row; i++)
        {
            for(int j = 0 ; j < size_col ; j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
                if(matrix[i][j] > target)
                {
                    break;
                }
            }
            if(matrix[i][0] > target)
            {
                return false;
            }
        }
        return false;
    }
};