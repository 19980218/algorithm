int lengthOfLIS(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
   vector<int> sum(nums.size(), 1);
   for (int i = 0; i < nums.size(); i++)
   {
       for (int j = 0; j <= i ; j++)
       {
           if (nums[i] > nums[j])
           {
               sum[i] = max(sum[i], sum[j] + 1);
           }
       }
   }
   int flag = sum[0];
   for (int i = 0; i < sum.size(); i++)
   {
       if (sum[i] > flag)
       {
           flag = sum[i];
       }
   }
   return flag;

}