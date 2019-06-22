long gcd(long m , long n)
{
    while(n != 0)
    {
        long temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}