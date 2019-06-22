bool judge(vector<pair<int , int> > &a, pair<int ,int> b)
{
    int maxs = -99999;
   for (auto pbe = a.begin(); pbe != a.end(); pbe++)
   {
       if (pbe->second > maxs)
       {
           maxs = pbe->second;
       }
   }
   int aim[maxs];
   for (auto pbe = a.begin(); pbe != a.end(); pbe++)
   {
       for (int i = pbe->first; i <= pbe->second; i++)
       {
           aim[i] = 1;
       }
   }

   for (int i = b.first; i <= b.second; i++)
   {
       if (aim[i] != 1)
       {
           return false;
       }
   }
   return true;
}