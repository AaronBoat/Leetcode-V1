#include <vector>
#include <cstddef>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool first_row_has_zero = false;
        bool first_col_has_zero = false;

        const size_t size_rows = matrix.size();
        const size_t size_cols = matrix[0].size();

        if(matrix[0][0] == 0)
        {
            first_row_has_zero = true;
            first_col_has_zero = true;
        }

        // first col
        for (int row_now = 0; row_now < size_rows; row_now++)
        {
            if (matrix[row_now][0] == 0)
            {
                first_col_has_zero = true;
            }
        }

        // first row
        for (int col_now = 1; col_now < size_cols; col_now++)
        {
            if (matrix[0][col_now] == 0)
            {
                first_row_has_zero = true;
            }
            for (int row_now = 1; row_now < size_rows; row_now++)
            {
                if (matrix[row_now][col_now] == 0)
                {
                    matrix[row_now][0] = 0;
                    matrix[0][col_now] = 0;
                }
            }
        }

        for (int i = 1; i < size_rows; i++)
        {
            for (int j = 1; j < size_cols; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(first_row_has_zero)
        {
            for(int col_now = 0 ; col_now < size_cols;col_now++)
            {
                matrix[0][col_now] = 0;
            }
        }
        if(first_col_has_zero)
        {
            for(int row_now = 0 ; row_now < size_rows ; row_now ++)
            {
                matrix[row_now][0] = 0;
            }
        }
    }
};