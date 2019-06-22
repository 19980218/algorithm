using namespace std;
class  Set{
private:
    class Node;
    class iterator{
    private:
        Node *current;
        friend class Set;
    public:
         iterator(Node *p):current(p){}
         iterator():current(NULL){}
         const int operator*() const
         {
             return current->data;
         }
         iterator & operator++()
         {
             current = current->right;
             return *this;
         }
         iterator & operator++(int)
         {
             iterator old = *this;
             current = current->right;
             return old;
         }
         bool operator==(const iterator &rhs) const
         {
             if (current == rhs.current)
             {
                 return true;
             }
             else
             {
                 return false;
             }
         }
         bool operator!=(const iterator &rhs) const
         {
             if (!(operator==(rhs)))
             {
                 return true;
             }
             else
             {
                 return false;
             }
         }

    };

    class Node{
    private:
        int data;
        Node *left;
        Node *right;
        Node(int a = 0, Node *p1 = NULL,Node *p2 = NULL):data(a),left(p1),right(p2){}

        friend class Set;
        friend class iterator;
    };
    iterator begin( Node *& tep) const
        {
            if (tep->left != NULL)
            {
                begin(tep->left);
            }
            else
            {
                return iterator(tep);
            }
        }
    iterator end( Node *& tep) const
        {
            if ( tep->right != NULL)
            {
                end(tep->right);
            }
            else
            {
                iterator(tep->right);
            }
        }
    const iterator find( Node* & tep,const int & a) const
    {
        if (tep != NULL)
        {
             if (a < tep->data)
            {
                find(tep->left,a);
            }
            else if (tep->data < a)
            {
                find(tep->right,a);
            }
            else
            {
                return iterator(tep);
            }
        }
        else
        {
            return iterator(NULL);
        }

    }
    Node * insert( Node * & tep,const int & x) const
    {
        if (tep == NULL)
        {
            return tep = new Node(x,NULL,NULL);
        }
        else if (x < tep->data)
        {
            return insert(tep->left, x);
        }
        else if(tep->data < x)
        {
            return insert(tep->right,x);
        }
        else
        {
            ;
        }
    }
    Node * clone(Node * & t) const
    {
        if (t == NULL)
            return NULL;
        return new Node(t->data,clone(t->left),clone(t->right));
    }
    void makeEmpty(Node * & t)
    {
        if ( t != NULL)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = NULL;
    }
    Node * findmin(Node * & tep) const
    {
        if (tep == NULL)
        {
            return NULL;
        }
        else if (tep->left == NULL)
        {
            return tep;
        }
        else
        {
            findmin(tep->left);
        }

    }
    Node * findmax(Node * & tep) const
    {
        if (tep == NULL)
        {
            return NULL;
        }
        else if (tep->right == NULL)
        {
            return tep;
        }
        else
        {
            findmin(tep->right);
        }

    }
    Node * erase(Node * & tep,const  int & x)
    {
            if (tep == NULL)
            {
                return NULL;
            }
            else if (x < tep->data)
            {
                erase(tep->left,x);
            }
            else if(tep->data < x)
            {
                erase(tep->right,x);
            }
            else if(tep->left != NULL && tep->right != NULL)
            {
                tep->data = findmin(tep->right)->data;
                erase(tep->right,tep->data);
                return tep;
            }
            else
            {
                Node * oldNode = tep;
                if (tep->left != NULL)
                    tep = tep->left;
                else
                    tep = tep->right;

                delete oldNode;
                return tep;
            }

    }
    void print(Node * &tep)
    {
        if ( tep != NULL)
        {
            print(tep->left);
            cout << tep->data;
            print(tep->right);

        }

    }
private:

    Node *root;

public:
    void makeEmpty()
    {
        makeEmpty(root);
    }
    Set(Node * p = NULL):root(p){}
    Set(const Set & rhs)
    {
        root = rhs.root;
    }
    const Set & operator=( Set & rhs)
    {
        if(this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    }
    ~Set()
    {
        makeEmpty();
    }
    iterator begin()
    {
        if(root != NULL)
        {
            begin(root);
        }

    }
    iterator end()
    {
        end();
    }
    iterator find(const int & a)
    {
      return  find(root,a);
    }
    iterator insert(const int & x)
    {
        return iterator(insert(root,x));
    }
    iterator erase(const int x)
    {
        return iterator(erase(root,x));
    }
    void print()
    {
        print(root);
    }

};