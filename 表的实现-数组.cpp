template <typename object>
class Vector{
public:
    explicit Vector( int initsize = 0)
        :thesize(initsize),thecapacity(initsize + SPARE_CAPACITY)
        {
            objects = new object[thecapacity];
        }
        Vector( const Vector & rhs ): objects(NULL)
        {
            operator=(rhs);
        }
        ~Vector()
        {
            delete [] objects;
        }
        const Vector & operator=(const Vector & rhs);
        void resize(int newsize);
        void reserve(int newcapacity);
        object & operator[](int index);
        const object & operator[](int index) const ;
        bool empty() const;
        int size() const;
        int Capacity() const;
        void push_back(const object & x);
        void pop_back();
        const object & back() const;
        typedef object * iterator ;
        typedef const object * const_iterator;
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        enum {SPARE_CAPACITY = 16};
private:
    int thesize;
    int thecapacity;
    object * objects;

};
const Vector<object> & Vector<object>::operator=(const Vector<object> & rhs)
{
    if (this != &rhs)
    {
        delete [] objects;
        thesize = rhs.size();
        thecapacity = rhs.thecapacity;

        objects = new object[Capacity()];
        for (int k = 0;k < size(); k++)
        {
            objects[k] = rhs.objects[k];
        }
    }
    return *this;
}
void Vector::resize( int newsize)
{
    if (newsize > thecapacity)
        reserve(newsize * 2 + 1);
    thesize = newsize;
}
void Vector::reserve(int newcapacity)
{
    if (newcapacity <thesize)
    {
        return ;
    }
    object * oldarry = objects;

    objects = new object[newcapacity];
    for (int k = 0; k < thesize ; k++)
    {
        objects[k] = oldarry[k];
    }
    thecapacity = newcapacity;
    delete [] oldarry;
}
object & Vector::operator[](int index)
{
    return objects[index];
}
const object & Vector::operator[](int index) const
{
    return objects[index];
}
bool Vector::empty()
{
    return size() == 0;
}
int Vector::size() const
{
    return thesize;
}
int Vector::capacity() const
{
    return thecapacity;
}
void Vector::push_back( const object & x)
{
    if (thesize == thecapacity)
    {
        reserve( 2 * thecapacity + 1);
    }
    objects[ thesize ] = x;
}
void Vector::pop_back()
{
    thesize--;
}
const object & Vector::back() const
{
    return objects[thesize - 1];
}
iterator Vector::begin()
{
    return &objects[0];
}
const_iterator Vector::begin() const
{
    return &objects[0];
}
iterator Vector::end()
{
    return &objects[size()];
}
const_iterator Vector::end() const
{
    return &objects[size()];
}
