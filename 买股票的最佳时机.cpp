int maxProfit(vector<int>& prices)//方法一
{
    if (prices.size() == 0)
        return 0;
    int maxs = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)

        {

            if (prices[j] - prices[i] > maxs)
                maxs = prices[j] - prices[i];
        }
    }
    return maxs;
}
int maxProfit(vector<int>& prices)//方法二
{
    int maxs = 0;
    int temp = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[temp] > prices[i])
        {
            temp = i;
            continue;
        }
        else
        {
            if (prices[i]-prices[temp] > maxs)
            {
                maxs = prices[i]-prices[temp];

            }
        }
    }
    return maxs;
}