#include <queue>
using namespace std;

class Solution
{
private:
    int num_o = 0;
    queue<tuple<int,int,int> > B; // x,y,time
    int row_size;
    int col_size;
    int move_x[4] = {0, -1, 0, 1};
    int move_y[4] = {1, 0, -1, 0};
    inline bool valid(int x, int y)
    {
        return x >= 0 && x < row_size && y >= 0 && y < col_size;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        num_o = 0;
        row_size = grid.size();
        col_size = grid[0].size();
        int time_stamp = 0;
        int max_time = 0 ;
        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                if (grid[i][j] == 1)
                {
                    num_o++;
                }
                if (grid[i][j] == 2)
                {
                    B.push({i, j,0});
                }
            }
        }
        /*
cout << "first num_1: "<<num_o<<'\n';
        */
        while (!B.empty())
        {
            auto now = B.front();
            B.pop();
            auto [x,y,t] = now;
            /*
cout << " at time : "<<t<<" at x,y: "<<x<<" "<<y<<" is source "<<'\n';
            */
            max_time = max(max_time , t);

            for (int i = 0; i < 4; i++)
            {
                int nx = x + move_x[i];
                int ny = y + move_y[i];
                if (valid(nx, ny))
                {
                    if(grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        num_o --;
                        B.push({nx,ny,t + 1});
                        /*
cout<<" at time t : "<<t<<" infected nx,ny: "<<nx<<" "<<ny<<" rest num_1: "<<num_o<<'\n';
                        */
                    }
                }
            }
        }
        /*
cout << "final num_1: "<< num_o<<'\n';
        */
        if(num_o > 0)
        {
            return -1;
        }
        else 
        {
            return max_time;
        }

    }
};