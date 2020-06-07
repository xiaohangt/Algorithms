#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    long long a,b,t,k;
    int bu[1000000001];
    while(cin>>a>>b)
    {
        if (a>b)
        {
            t=a;a=b;b=t;
        }
        t=1;memset(bu,0,sizeof(bu));
        k=1;bu[2]=1;
        while (k<=a)
        {
            if (bu[k]!=1)
            {
                bu[k+t]=1;
                ++t;
                ++k;
            }
            else ++k;
        }
        if (bu[b]==1) cout<<"0"<<endl;
        else cout<<"1"<<endl;
        
    }
}