template <typename Comparable>
void headsort( vector<Comparablez> &a)
{
    for( int i = a.size() / 2; i >=0; i-- )
    {
        percDown(a,i,a.size());
    }
    for (int j = a.size() - 1; j > 0; j-- )
    {
        swap(a[0],a[j]);
        percDown(a,0,j);
    }
}

inline int leftChild(int i)
{
    return 2 * i + 1;
}

template <typename Comparable>
void percDown(vector<Comparable> &a, int i,int n)
{
    int child;
    Comparable tmp;
    for(tmp = a[i]; leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if(child != n - 1 && a[child] < a[child + 1])
            child++;
        if(tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}