int backet01(vector<int> capacity, vector<int> value,int max_capacity)
{

    int dp[3][5] = {{0}};
    for (int i = 0; i <= max_capacity; i++)
    {
        if (i >= capacity[0])
        {
            dp[0][i] = value[0];
            //cout << "hh" << endl;
        }
    }
    ///行和列的交叉点代表将前j件物品列为备选，背包容量为i时，能获得的最大价值
    for (int i = 0; i <= max_capacity; i++)///表示列，代表的意义是当前背包的容量
    {
        for (int j = 1; j < capacity.size(); j++)///表示行，代表的意义是将前j件物品列为备选
        {
            if (i >= capacity[j])
            {
                dp[j][i] = max(dp[j-1][i-capacity[j]] + value[j],dp[j-1][i]);
            }
            else
            {
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    for (int i = 0 ; i < capacity.size(); i++)
    {
        for (int j = 0; j <= max_capacity; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
    return dp[capacity.size()-1][max_capacity];
}
