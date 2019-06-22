int longest_increasing_list(int *A,int n)
{
    int current_counter;
    int max_counter = 1;
    for(int i = 0; i < n - 1; i++)
    {
        current_counter = 1;

        for(int j = i,k = i + 1; k < n  ; k++)
        {
            if (A[k] > A[j])
            {
                current_counter++;
                j = k;
            }
        }
        if (current_counter > max_counter)
        {
            max_counter = current_counter;
        }
    }
    return max_counter;
}

int longest_increasing_list2(int a[], int n)
{
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && b[j] + 1 > b[i])
            {
                b[i] = b[j] + 1;
            }
            else if (a[i] <= a[j] && b[j] > b[i])
            {
                b[i] = b[j];
            }
            else
            {

            }
        }
    }
    return b[n-1  ];
}