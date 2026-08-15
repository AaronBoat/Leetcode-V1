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

        int x = 0 , y = size_col - 1;

        
        for (int i = 0; i < size_row; i++)
        {
            for(int j = 0 ; j <= back_col ; j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
                if(matrix[i][j] > target)
                {
                    back_col = j - 1;
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