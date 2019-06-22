#include<iostream>
#include<istream>
#include<fstream>
#include<ostream>
#include<string>
#include<list>
#include<vector>
#include<array>
#include<deque>
#include<algorithm>
#include<iterator>
#include<map>
#include<utility>
#include<set>
#include<memory>
#include<sstream>

using namespace std;
using namespace placeholders;
class StrVec{
public:
    StrVec():
        elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    ~StrVec();
    StrVec &operator=(const StrVec&);
    void push_backs(const string&);
    size_t sizes() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string *begins() const {return elements;}
    string *ends() const {return first_free;}
private:
    allocator<string> alloc;
    void chk_n_alloc()
        {
            if (sizes() == capacity())
                reallocate();
        }
    pair<string*,string*>alloc_n_copy
        (const string*,const string*);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;

};
void StrVec::push_backs(const string & s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
pair<string*,string*> StrVec::alloc_n_copy(const string *b,const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data,uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;  )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begins(),s.ends());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begins(),rhs.ends());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
void StrVec::reallocate()
{
    auto newcapacity = sizes() ? 2 * sizes() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != sizes(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}