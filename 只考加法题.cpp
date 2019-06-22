void Add(int n)
{
    int sum;
    int flag = 0;
     for (int i = 1; i < n; i++)
     {
         sum = i;
         for (int j = i + 1; j < n; j++)
         {

             sum = sum + j;
             if ( sum == n)
             {
                 flag = 1;
                 for (int k = i; k <= j; k++)
                    cout << k << " " ;
                 cout << endl;
             }

         }
     }
     if ( flag == 0)
     {
         cout << " I can't find it!" << endl;
     }
}