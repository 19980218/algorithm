int Find_min_distance(vector<pair<int,int> > & a)
{
    int distance;
    int distance_min = 10000000000;
    for (auto p = a.begin(); p != a.end(); p++)
    {
        for (auto q = (p+1); q != a.end(); q++)
        {
            distance = (p->first - q->first)*(p->first - q->first) + (p->second - q->second)*(p->second - q->second);
            if (distance_min > distance)
            {
                distance_min = distance;
            }
        }
    }
    return distance_min;

}