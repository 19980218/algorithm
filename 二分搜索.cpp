template <typename object>
int binaryseach(const vector<object> &a, const object &x)
{
    int low = 0,high = a.size() - 1;
    while(low <= high)
    {
        int mid = ( low + high ) / 2;

        if ( a[mid] < x )
        {
            low = mid + 1;
        }
        else if ( a[mid] > x )
        {
            high = mid - 1;
        }
        else
            return mid;//代表返回所找元素的位置
    }
    return -1;
}
