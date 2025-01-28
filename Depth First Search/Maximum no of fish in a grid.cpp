// Leetcode problem no 2658

class Solution
{
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            return 0;
        }
        int fishcount = grid[i][j];
        grid[i][j] = 0;

        for (auto &dir : directions)
        {
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;
            fishcount += dfs(i_, j_, grid);
        }
        return fishcount;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int maxfish = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxfish = max(maxfish, dfs(i, j, grid));
            }
        }
        return maxfish;
    }
};