class lists{
public:
    int data = 100;
    lists *p = NULL ;
};
int judgement(lists *h1, lists *h2)
{
    lists *temp ;
    while(h1->p != NULL)
   {

       temp = h2;

       while(temp->p != NULL)
       {

           if (h1->p == temp->p)
           {

               return 1;
           }
           temp = temp->p;
       }

       h1 = h1->p;
   }
    return false;
}
bool judgement2(lists *h1, lists *h2)
{
    while (h1->p != NULL)
    {
        h1 = h1->p;
    }
    while (h2->p != NULL)
    {
        h2 = h2->p;
        if (h1 == h2)
            return true;
    }
    return false;
}