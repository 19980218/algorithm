int longs2(vector<vector<int> > &sum)//方法一
{
    if (sum[0][0] == 1 || sum[sum.size()-1][sum[0].size()-1] == 1)
        return 0;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
        {
            if (sum[i][j] == 1)
            {
                sum[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < sum[0].size(); i++)
    {
        if (sum[0][i] >= 0)
        {
            sum[0][i] = 1;

        }
        else
        {
            break;
        }

    }
    for (int i = 0; i < sum.size(); i++)
    {
        if (sum[i][0] >= 0)
        {
            sum[i][0] = 1;

        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
        {

            if (sum[i][j] < 0)
            {
                continue;
            }
            else
            {
                if (i != 0 && j != 0)
                {
                    if (sum[i-1][j] < 0 && sum[i][j-1] < 0)
                {
                    continue;
                }
                else if (sum[i-1][j] < 0 && sum[i][j-1] >= 0)
                {
                    sum[i][j] = 0 + sum[i][j-1];
                }
                else if (sum[i][j-1] < 0 && sum[i-1][j] >= 0)
                {
                    sum[i][j] = sum[i-1][j] + 0;
                }
                else
                {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1];
                }
                }

            }
        }
    }
    return sum[sum.size()-1][sum[0].size()-1];
}

int longs3(vector<vector<int> > &obstacleGrid)//方法二(将1变为0)
{
    if (obstacleGrid[0][0] == 1)
        return 0;
    for (int i = 0; i < obstacleGrid.size();  i++)
    {
        for (int j = 0; j < obstacleGrid[0].size(); j++)
        {
            //cout << "aa" << endl;
            if (i == 0 && j == 0)
            {
                obstacleGrid[i][j] = 1;
                continue;
            }

            else if (i == 0 || j == 0)
            {
                if (i == 0)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        obstacleGrid[i][j] = 0;
                    }
                    else
                    {
                        obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    }
                }
                if (j == 0)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        obstacleGrid[i][j] = 0;
                    }
                    else
                    {
                        obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    }
                }
            }

            else
            {
                if (obstacleGrid[i][j] == 1)
                {
                    obstacleGrid[i][j] = 0;
                }
                else
                {
                    obstacleGrid[i][j] =  obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
    }
    return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}