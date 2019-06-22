int compare(int x, int y)
{
    if ( x > y)
        return x;
    else
        return y;
}

int max_sum(int *p, int n)
{
    int start = p[n-1];
    int ends = p[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        start = compare(p[i], p[i] + start);
        ends = compare(start , ends);
    }
    return ends;
}
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