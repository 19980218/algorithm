int longs(int m, int n)//方法一
{
    int  (*sum)[m] = new int [n][m];
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j ==0)
            {
                sum[i][j] = 1;
            }
            else
            {

                sum[i][j] = sum[i-1][j] + sum[i][j-1];
            }
        }
    }
    return sum[n-1][m-1];
}


//方法二
void aaa(int i,int j, int row,int lists,int &o)
{
    if (i != row - 1)
    {
        aaa(i + 1, j,row,lists,o);
    }
    if (j != lists -1)
    {
        aaa(i,j+1,row,lists,o);
    }
//cout << i << j << row << lists << endl;
    if (i == row -1 && j == lists - 1)
    {

         o++;
    }


}

int aaa(int m, int n)
{
    int k;
    int i = 0,j =0;
    int o = 0;
    if (m == 1 || n == 1)
        return 1;
    else
    {
        aaa(i+1,j,n,m,o);
    aaa(i,j+1,n,m,o);
    return o;
    }



}