int Count1(char v)
{
    int num = 0;
    while(v)
    {
        if(v % 2 == 1)
        {
            num++;
        }
        v = v / 2;
    }
    return num;
}
int Count2(char v)
{
    int num = 0;
    while(v)
    {
        num += v & 0x01;
        v >>= 1;
    }
    return num;
}
int Count3(char v)
{
    int num = 0;
    while(v)
    {
        v &= (v-1);
        num++;
    }
    return num;
}