int maxsum(const vector<int> &a)
{
    int maxsum = 0,thissum = 0;
    for (int j = 0; j < a.size(); j++)
    {
        thissum += a[j];
        if (thissum > maxsum)
        {
            maxsum = thissum;
        }
        else if(thissum < 0)
        {
            thissum = 0;
        }
    }
    return maxsum;
}