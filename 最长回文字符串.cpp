bool hange(string str, int i ,int j)
{
    string str1 = str;
    char temp;
    int n1,n2;
    n1 = i;
    n2 = j;
    while(i < j)
    {
         temp = str[i];
         str[i] = str[j];
         str[j] = temp;
         //cout << str[i] << " " << str[j] << endl;
         i++;
         j--;
    }
    int flag = 0;
    //cout << "str = " << str << endl << "str1 = " << str1 << endl;
    for (int i = n1; i <= n2; i++ )
    {
        if (str1[i] == str[i])
            flag++;
    }
    //cout << flag << endl;
    if (flag == n2-n1+1)
        return true ;
    else
        return false;
}
string solution(string s)
{
    int n;
    int be = 0;
    int en = 0;
    int couter = 0;
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            //cout << hange(s,i,j) << endl;
            if ( hange(s,i,j))
            {
                be = i;
                en = j;
                if (en - be > couter)
                {
                    couter = en-be;
                    flag = i;
                    //cout <<couter << endl;
                }
                  //cout << be << en << endl;
            }
        }
    }


    string s1 = " ";
    return s.substr(flag,couter+1);
}