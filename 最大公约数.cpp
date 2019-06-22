int gcd(int x, int y)
{
    return (!y)?x:gcd(y,x%y);
}
int gcd1(int x,int y)
{
    if (x < y)
    {
        return gcd1(y,x);
    }
    if (y == 0)
    {
        return x;
    }
    else
    {

        return gcd1(x-y, y);
    }
}
int IsEven(int x)
{
    if ((x % 2) == 0)
        return 1;
    else
        return 0;
}
int gcd2(int x, int y)
{
    if (x < y)
    {
        return gcd2(y,x);
    }
    if (y == 0)
    {
        return x;
    }
    else
    {
        if (IsEven(x))
        {
            if (IsEven(y))
                return (gcd2(x >> 1, y >> 1) << 1);
            else
                return gcd2(x >> 1, y);
        }
        else
        {
            if (IsEven(y))
                return gcd2(x , y >> 1);
            else
                return gcd2(y, x- y);
        }
    }
}