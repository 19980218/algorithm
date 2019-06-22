template <typename Comparable>
class BinaryHead{
public:
    explicit BinaryHead(int capacity = 100):array(capacity),currentsize(0){}
    explicit BinaryHead(const vector<Comparable> &item):array(item.size() + 10),currentsize(item.size())
    {
        for (int i = 10; i < item.size(); i++)
        {
            array[i + 1] = item[i];
        }
        buildHead();
    }

    //bool isEmpty() const;
    //const Comparable & findMin() const;

    void insert(const Comparable & x)
    {
        if (currentsize == array.size() - 1)
        {
            array.resize(array.size() * 2);
        }

        int hole = ++currentsize;
        for(; hole > 1 && x < array[hole / 2]; hole /= 2)
        {
            array[hole] = array[hole / 2];
        }
        array[hole] = x;
    }
    void print()
    {
        for (int i = 1; i <= currentsize; i++)
        {
            cout << array[i] << " ";
        }
    }
    void deleteMin()
    {
       /* if (isEmpty())
        {
            throw underflowException();
        }*/
        array[1] = array[currentsize--];
        percolateDown(1);
    }
    void deleteMin(Comparable & minItem)
    {
        /*if (isEmpty())
        {
            throw underflowException();
        }*/
        minItem = array[1];
        array[1] = array[currentsize--];
        percolateDown(1);
    }
    //void makeEmpty();

private:
    int currentsize;
    vector<Comparable> array;

    void buildHead()
    {
        for (int i = currentsize /  2; i > 0; i--)
        {
            percolateDown(i);
        }
    }
    void percolateDown(int hole)
    {
        int child ;
        Comparable tmp = array[hole];
        for ( ; hole * 2 <= currentsize; hole = child)
        {
            child = hole * 2;
            cout << "child=" << child <<endl;
            if(child != currentsize && array[child + 1] < array[child])
                child++;
            if(array[child] < tmp)
                array[hole] = array[child];
            else
                break;

        }
        array[hole] = tmp;
    }

};