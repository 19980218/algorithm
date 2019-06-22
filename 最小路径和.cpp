int min_long(vector<vector<int> >& grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0 || j == 0)
            {

                if (i == 0)
                {

                  grid[i][j] = grid[i][j] + grid[i][j-1];
                }
                else
                {
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                }

            }
            else
            {
                if ((grid[i-1][j] + grid[i][j]) > (grid[i][j-1] + grid[i][j]))
                {
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }
                else
                {
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }
            }

        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}