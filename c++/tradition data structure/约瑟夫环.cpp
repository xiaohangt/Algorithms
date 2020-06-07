#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int n,s,m;
class Josephus {//link
private:
    class Josephus * next;//next point
    int x;
public:
    
    void setJosephus(Josephus * head)
    {
        Josephus * h=new Josephus;
        head->x=1;
        head->next=h;
        for (int i=2;i<=n;++i)
        {
            h->x=i;
            if (i==n) h->next=head;
            else
            {
            Josephus * p=new Josephus;
            h->next=p;
            h=h->next;
            }
        }
        h->next=head;
    }//setting up a link
    
    void runJosephus(Josephus * head)
    {
        Josephus * k=head;
        for (int i=1;i<=n;++i)
        {
            if (i==s) break;
            else k=k->next;
        }
        int g=m;
        while (k->next!=NULL)
        {
            --g;//counting numbers
            if (g==1)
            {
                g=m;
                Josephus * kk=k->next;//kk is the next point of k
                cout<<kk->x<<endl;
                if (k==kk->next)
                {
                    cout<<k->x<<endl;//leaving the last two points we output one
                    break;
                }
                else
                {
                    k->next=kk->next;
                    k=kk->next;//delete the point
                }
            }
            else
            {
                if (g==0)//solving the problems when m==1
                {
                    for (int i=1;i<=n;++i)
                    {
                        cout<<k->x<<endl;
                        k=k->next;
                    }
                    break;
                }
                else k=k->next;
            }
        }
    }
};
int main() {
    
    cin>>n>>s>>m;
    Josephus t,* head= new Josephus,* q1=new Josephus;
    t.setJosephus(head);
    t.runJosephus(head);
}