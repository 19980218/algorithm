void ranse(int maps[][3], int i, int j, int c, int m, int n)
{
    if (i > m-1 || j > n -1 )
    {
        return ;
    }
    int init = maps[i][j];
    maps[i][j] = c;
    if (i-1>= 0 )
    {
        if (maps[i-1][j] == init)
        ranse(maps, i-1 , j , c, m, n);

    }
    if (i+1 < m )
    {
        if (maps[i+1][j] == init)
        ranse(maps, i+1, j, c, m, n);
    }
    if (j+1< n )
    {
        if (maps[i][j+1] == init)
        ranse(maps, i, j+1, c,m ,n);
    }
    if (j-1 >= 0 )
    {
        if (maps[i][j-1] == init)
        ranse(maps , i , j-1 ,c, m , n);
    }
}