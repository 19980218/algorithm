int backet01(vector<int> capacity, vector<int> value,int max_capacity)
{

    int dp[3][5] = {{0}};
    for (int i = 0; i <= max_capacity; i++)
    {
        if (i >= capacity[0])
        {
            dp[0][i] = value[0];
            //cout << "hh" << endl;
        }
    }
    ///�к��еĽ�������ǰj����Ʒ��Ϊ��ѡ����������Ϊiʱ���ܻ�õ�����ֵ
    for (int i = 0; i <= max_capacity; i++)///��ʾ�У�����������ǵ�ǰ����������
    {
        for (int j = 1; j < capacity.size(); j++)///��ʾ�У�����������ǽ�ǰj����Ʒ��Ϊ��ѡ
        {
            if (i >= capacity[j])
            {
                dp[j][i] = max(dp[j-1][i-capacity[j]] + value[j],dp[j-1][i]);
            }
            else
            {
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    for (int i = 0 ; i < capacity.size(); i++)
    {
        for (int j = 0; j <= max_capacity; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
    return dp[capacity.size()-1][max_capacity];
}
