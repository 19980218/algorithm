class stack
{
private :
    int stackitem[50];
    int stacktop;
    int link2nextmaxitem[50];
    int maxstackitemindex;

public:
    stack()
    {
        stacktop = -1;
        maxstackitemindex = -1;
    }
    void push(int x)
    {
        stacktop++;
        if (stacktop >= 50)
        {
            ;
        }
        else
        {
            stackitem[stacktop] = x;
            if (x > Max())
            {
                link2nextmaxitem[stacktop] = maxstackitemindex;
                maxstackitemindex = stacktop;
            }
            else
            {
                link2nextmaxitem[stacktop] = -1;
            }
        }
    }
    int pop()
    {

        int ret;
        if (stacktop < 0)
        {
            ;
        }
        else
        {
            ret = stackitem[stacktop];
            if (stacktop == maxstackitemindex)
            {
                maxstackitemindex = link2nextmaxitem[stacktop];
            }
            stacktop--;
        }
        return ret;
    }
    int Max()
    {
        if (maxstackitemindex >= 0)
        {
            return stackitem[maxstackitemindex];
        }
        else
        {
            return -INF;
        }
    }

};