#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        const int x_size = grid.size();
        const int y_size = grid[0].size();
        
        auto is_inside = [x_size, y_size](int x, int y)
        {
            return x >= 0 && x <= x_size && y >= 0 && y <= y_size;
        };
        if(!is_inside(x,y))
        {
            return;
        }
        if (grid[x][y] == 0 )
        {
            return;
        }

        grid[x][y] = '0';
        int move_x[4] = {1, 0, -1, 0};
        int move_y[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            dfs(x + move_x[i], y + move_y[i], grid);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        const int x_size = grid.size();
        const int y_size = grid[0].size();
        for (int i = 0; i <x_size ; i++)
        {
            for(int j = 0 ; j<y_size;j++)
            {
                if(grid[i][j] == '0')
                {
                    ans ++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};