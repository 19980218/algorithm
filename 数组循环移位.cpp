void reverses(int *a, int b, int e)
{
    int temp;
    for(; b < e; b++, e--)
    {
        int temp = a[e];
        a[e] = a[b];
        a[b] = temp;
    }
}
int rightshift(int *a, int n,int k)
{
    k = k % n;
    reverses(a,0,n-k-1);
    reverses(a,n-k,n-1);
    reverses(a,0,n-1);
}