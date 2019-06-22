bool KMP(string str, string pattar)
{
    char next[pattar.size()];
    if (pattar.size() == 1)
    {
        next[0] = 0;
    }
    else if (pattar.size() == 2)
    {
        next[0] = 0;
        next[1] = 0;
    }
    else
    {
         next[0] = 0;
        next[1] = 0;
    }
    int j;
    for (int i = 2; i < pattar.size(); i++)
    {
       j = next[i-1];
        while(true)
        {
            if (j == 0 && (pattar[j] != pattar[i-1]))
            {
                next[i] = 0;
                break;
            }
            else if (pattar[j] == pattar[i-1])
            {
                next[i] = next[i-1] + 1;
                break;
            }
            else
            {
                j = next[j];
            }
        }
    }
    int flag = 0;
    for (int i = 0,k=0; i < str.size() && k < pattar.size(); i++)
    {
        if (pattar[k] == str[i])
        {
            flag++;
            k++;
            if (flag == pattar.size())
            {
                return true;
            }
            continue;
        }
        else
        {
            k = next[k];
            flag = k;
            continue;
        }
    }
    return false;

}