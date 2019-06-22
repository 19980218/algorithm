#define ITF 100000
int C[5] = {3,4,5,6,2};
int v[5] = {2,2,2,2,2};
int H[5] = {20,440,10,10,20};
int opt[10][10];
int Cal(int V, int T)
{
    opt[0][T] = 0;
    for(int i = 1; i <= V; i++)
    {
        opt[i][T] = -ITF;
    }
    for(int j = T - 1; j >= 0; j--)
    {
        for(int i = 0; i <= V; i++)
        {
            opt[i][j] = -ITF;
            for(int k = 0; k <= C[j]; k++)
            {
                if(i < k * v[j])
                {
                    break;
                }
                int x = opt[i-k*v[j]][j+1];
                if(x != -ITF)
                {
                    x += H[j] * k;
                    if(x > opt[i][j])
                    {
                        opt[i][j] = x;
                    }
                }
            }
        }
    }
    return opt[V][0];
}

