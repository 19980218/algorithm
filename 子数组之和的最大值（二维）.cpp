int max_sum2(int *p, int n)
{
    int start = p[n-1];
    int ends = p[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (p[i] > (p[i] + start))
        {
            start = p[i];
        }
        else
            start = p[i] + start;

        if (start > ends)
            ends = start;
    }
    return ends;
}
int maxsum(int a[][3], int n, int m)//方法一
{
    int b[m];
    int sum;
    int maxs = -99999;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int l = 0 ; l < m; l++)//l表示每列
            {
                sum = 0;
                for (int r = i; r <= j; r++)//r表示在i-j之间的每行
                {
                    sum = sum + a[r][l];
                }
                b[l] = sum;
            }

            if (max_sum2(b,m) > maxs)
            {
                    maxs = max_sum2(b,m);
            }
        }
    }
    return maxs;
}
int BC(int a[][3],int row1,int row2, int line )
{
    int sum = 0;
    for (int i = row1; i <= row2; i++)
    {
        sum = sum + a[i][line];
    }
    return sum;
}
int maxsum2(int a[][3], int n, int m )//方法二
{
    int start;
    int ends;
    int temp;
    int maxs = -999999;
    for (int i = 0; i < n; i++)
    {
        for (int j = i ; j < n; j++)
        {
            start = BC(a,i,j,m-1);
            ends = BC(a,i,j,m-1);
            for (int l = m - 2; l >= 0; l--)
            {
                temp = BC(a,i,j,l);
                if (temp > (temp + start))
                {
                    start = temp;
                }
                else
                {
                    start = start + temp;
                }

                if (start > ends)
                    ends = start;
            }

            if (ends > maxs)
            {
                maxs = ends;
            }
        }
    }
    return maxs;
}
