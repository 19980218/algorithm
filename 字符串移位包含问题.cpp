void ShiftOne(char *p, int n)
{
  char temp = p[0];

  for (int i = 0; i < n - 1; i++)
  {
      p[i] = p[i+1];
  }
    p[n - 1] = temp;
}

bool judgement(char *p1,int n, char *p2,int m)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            flag = 0;

            for (int k = j, t = 0; k < n && t < m; k++, t++ )
            {
                if (p1[k] != p2[t])
                {
                    break;
                }
                if (p1[k] == p2[t])
                {
                    flag++;
                }
            }
            if (flag == m)
                return true;

        }
        ShiftOne(p1,n);
    }

        return false;
}