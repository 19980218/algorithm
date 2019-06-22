int countNumbersWithUniqueDigits (int n)
{
    if (n == 0)
        return 1;
    vector<int> sum(n, 0);
    sum[0] = 10;
    if (n == 1)
        return sum[n-1];

    int counts = 0;
    for (int i = 1; i < n; i++)
    {
        counts = 0;
        for (int j = 0; j < (i-1); j++)
        {
            counts = counts + sum[j];
        }
        sum[i] = (10 - i) * sum[i-1] + counts + 1;
    }
    return sum[n-1];

}