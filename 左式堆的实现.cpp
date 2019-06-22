template <typename Comparable>
class LeftistHeap
{
public:
    LeftistHeap() :root(NULL){}
    LeftistHeap(const LeftistHeap &rhs)
    {
        *this = rhs;
    }
    ~LeftistHeap()
    {
        MakeEmpty();
    }

    bool IsEmpty() const;
    const Comparable &FindMin() const;

    void Insert(const Comparable &x);
    void DeleteMin();
    void DeleteMin(Comparable &minItem);
    void MakeEmpty();
    void Merge(LeftistHeap &rhs);

    const LeftistHeap &operator=(const LeftistHeap &rhs);

private:
    struct LeftistNode
    {
        Comparable element;
        LeftistNode *left;
        LeftistNode *right;
        int npl;

        LeftistNode(const Comparable &theElement, LeftistNode *lt = NULL, LeftistNode *rt = NULL, int np = 0) :
            element(theElement), left(lt), right(rt), npl(np){}
    };
    LeftistNode *root;

    LeftistNode *Merge(LeftistNode *h1, LeftistNode *h2);
    LeftistNode *Merge1(LeftistNode *h1, LeftistNode *h2);

    void SwapChildren(LeftistNode *t);
    void ReclaimMemory(LeftistNode *t);
    LeftistNode *Clone(LeftistNode *t) const
    {
        if (t == NULL)
            return NULL;
        else
            return new LeftistNode(t->element, clone(t->left), clone(t->right));
    }

};



template <typename Comparable>
bool LeftistHeap<Comparable>::IsEmpty() const
{
    return root == NULL;
}

template <typename Comparable>
void LeftistHeap<Comparable>::Insert(const Comparable &x)
{
    root = Merge(new LeftistNode(x), root);
}

template <typename Comparable>
void LeftistHeap<Comparable>::Merge(LeftistHeap &rhs)
{
    if (this == &rhs)//避免和自己合并
        return;
    root = Merge(root, rhs.root);
    rhs.root = NULL;
}

template <typename Comparable>
void LeftistHeap<Comparable>::SwapChildren(LeftistNode *t)
{
    LeftistNode *tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}

template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode *LeftistHeap<Comparable>::Merge1(LeftistNode *h1, LeftistNode *h2)
{
    if (h1->left == NULL)
    {
         h1->left = h2;
          cout << "a"<< h1->element << endl;
    }

    else
    {
        h1->right = Merge(h1->right, h2);
        cout << h1->element << endl;
        if (h1->left->npl < h1->right->npl)
            SwapChildren(h1);
        h1->npl = h1->right->npl + 1;
    }
    return h1;
}

template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode *LeftistHeap<Comparable>::Merge(LeftistNode *h1, LeftistNode *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    if (h1->element < h2->element)
        return Merge1(h1, h2);
    else
        return Merge1(h2, h1);
}





template <typename Comparable>
void LeftistHeap<Comparable>::DeleteMin()
{
    if (IsEmpty())
        return;
    LeftistNode *oldRoot = root;
    root = Merge(root->left, root->right);
    delete oldRoot;
}


template <typename Comparable>
void LeftistHeap<Comparable>::DeleteMin(Comparable &minItem)
{
    minItem = FindMin();
    DeleteMin();
}

template <typename Comparable>
const Comparable & LeftistHeap<Comparable>::FindMin() const
{
    if (!IsEmpty())
        return root->element;
}


template <typename Comparable>
void LeftistHeap<Comparable>::ReclaimMemory(LeftistNode *t)
{
    if (t != NULL)
    {
        ReclaimMemory(t->left);
        ReclaimMemory(t->right);
        delete t;
    }
}


template <typename Comparable>
void LeftistHeap<Comparable>::MakeEmpty()
{
    ReclaimMemory(root);
    root = NULL;
}