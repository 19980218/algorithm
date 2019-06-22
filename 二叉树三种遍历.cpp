class Node
{
private:
    friend class Tree;
    int data = 0;
    Node *left = NULL;
    Node *right  = NULL;
public:
    Node(int a,Node *p1, Node *p2 )
    {
        data = a;
        left = p1;
        right = p2;
    }
};

class Tree
{
   private:

       Node *root = NULL ;
    void push(int &rhs , Node * &p)
    {
        if (p == NULL)
        {
            p = new Node(rhs,NULL,NULL);
        }
        else if (p->data > rhs )
        {
            push(rhs, p->left);
        }
        else if (p->data < rhs)
        {
            push(rhs, p->right);
        }
        else
        {
            ;
        }
    }
    void xianxu(Node *p)
    {
        if (p != NULL)
        {
            cout << p->data;
            xianxu(p->left);
            xianxu(p->right);
        }
    }
    void zhonxu(Node *p)
    {
        if (p != NULL)
        {
            zhonxu(p->left);
            cout << p->data;
            zhonxu(p->right);
        }
    }
    void houxu(Node *p)
    {
        if (p != NULL)
        {
            houxu(p->left);
            houxu(p->right);
            cout << p->data;
        }
    }
   public:
    void push(int &rhs)
    {
       push(rhs,root);
    }

    void xianxu()
    {
       xianxu(root);
    }
    void zhonxu()
    {
        zhonxu(root);
    }
    void houxu()
    {
        houxu(root);
    }

};