long pow(long x,int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    if (!(n % 2))
    {
        return pow(x * x, n / 2);
    }
    else
        return pow(x * x, n / 2) * x;
}