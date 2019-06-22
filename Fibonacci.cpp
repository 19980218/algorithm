int Fibonacci(int n)
{
    if ( n <= 0)
    {
        return 0;
    }
    else if ( n == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci( n - 2);
    }
}
double Fibonacci2(int day)
{
    double start = 1;
    double start1 = 1;
    double temp = 0;
    if (day == 1 || day == 2)
    {
        return 1;
    }
    for (int i = 2; i < day; i++)
    {
        temp = start + start1;
        start1 = start;
        start = temp;
    }
    return temp;
}