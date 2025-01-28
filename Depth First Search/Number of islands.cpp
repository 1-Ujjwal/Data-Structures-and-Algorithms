// Leetcode problem no 200.

class Solution
{
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';

        for (auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(i_, j_, grid);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int countisland = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    countisland++;
                }
            }
        }
        return countisland;
    }
};