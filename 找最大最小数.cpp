void  Find_max_and_min(vector<int> &a)
{
    int maxs = a[0];
    int mins = a[1];
    for (auto begins = a.begin(); begins != a.end(); begins++ )
    {
        if ((*begins) < mins)
            mins = *begins;
        if ((*begins) > maxs)
            maxs = *begins;
    }
    cout << maxs << endl << mins;
}