 int coinChange(vector<int>& coins, int amount) {
        vector<int> sum(amount+1, 1000000-1);
        sum[0] = 0;
        for (int i = 0; i <= amount; i ++)
        {
            for (int j = 0 ; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                {
                    sum[i] = min(sum[i], sum[i - coins[j]] + 1);

                }

            }
            //cout <<sum[i] << " ";
        }

        if (sum[amount] == 1000000-1)
            return -1;
        else
            return sum[amount];
    }