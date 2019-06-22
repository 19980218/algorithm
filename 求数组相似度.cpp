int minvalue(int i, int j,int k)
{
    int temp = i ;
    if ( temp > j)
    {
        temp = j;
    }
    if ( temp > k)
    {
        temp = k;
    }
    return temp;
}
int similar_degree(string strA,int pAbegin,int pAend,string strB,int pBbegin,int pBend )
{
    if (pAbegin > pAend)
    {
        if (pBbegin > pBend)
        {
            return 0;
        }
        else
        {
            return pBend - pBbegin + 1;
        }
    }
    if (pBbegin > pBend)
    {
        if (pAbegin > pAend)
        {
            return 0;
        }
        else
        {
            return pAbegin - pAend + 1;
        }
    }
    if (strA[pAbegin] == strB[pBbegin])
    {
        return similar_degree(strA, pAbegin+1, pAend, strB, pBbegin+1, pBend );
    }
    int i,j,k;
    i = similar_degree(strA, pAbegin+1, pAend, strB, pBbegin+1, pBend );
    j = similar_degree(strA, pAbegin+1, pAend, strB, pBbegin, pBend );
    k = similar_degree(strA, pAbegin, pAend, strB, pBbegin+1, pBend );
    return minvalue(i,j,k) + 1;
}