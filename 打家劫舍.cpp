int aaa(vector<int>& sum, int n)
{
    int temp = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (sum[i] > temp)
        {
            temp = sum[i];
        }
    }
    return temp;
}
int rob(vector<int>& nums) {


       vector<int> sum(nums.size());
       for (int i = 0; i < nums.size(); i++)
       {
           if (i == 0 || i == 1)
           {
                sum[i] = nums[i];
           }
           else
           {
               sum[i] = nums[i] + aaa(sum,i);
           }
       }

       int temp = 0;
       for (int i = 0; i < sum.size(); i++)
       {
           if (sum[i] > temp)
           {
               temp = sum[i];
           }
       }
       return temp;

    }