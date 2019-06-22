int ddd(int n)
{
    int i;
    int person[n];
    for ( i=1;i<=n;i++)
        person[i]=i+1;
    int minfloor,targetfloor;
    int n1,n2,n3;

    for(n1=0, n2=person[1], n3=0,  i=2; i<=n; i++)
    {
        n3 += person[i];
        minfloor += person[i] * (i-1);
    }
    for( i=2; i<=n; i++)
    {
        if(n1 + n2 < n3)
        {
            targetfloor = i;
            minfloor += (n1+n2-n3);
            n1 += n2;
            n2 = person[i];
            n3 -= person[i];
        }
        else
        {
            break;
        }
    }
    return targetfloor;
}
int main()
{

 int n = ddd(4);
 cout << n;
return 0;
}
