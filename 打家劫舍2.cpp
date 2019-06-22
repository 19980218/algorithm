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

        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
       vector<int> sum(nums.size());
       for (int i = 0; i < nums.size()-1; i++)
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
        vector<int> sum1(nums.size());
        sum1[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i == 1 || i == 2)
            {
                sum1[i] = nums[i];
            }
            else
            {
                sum1[i] = nums[i] + aaa(sum1,i);
            }
        }
        sum[nums.size()-1] = sum1[nums.size()-1];
       int temp = 0;
       for (int i = 0; i < sum.size(); i++)
       {
           //cout << sum[i];
           if (sum[i] > temp)
           {
               temp = sum[i];
           }
       }
       return temp;

    }