#include <iostream>
#include <cstring>
using namespace std;
int i,j;
void cheng(int a[100])
{
    i=1;
    j=1;
    while (0<=a[i] && a[i]<=9)
    {
        a[i]=a[i]*3;
        ++i;
    }
    while (0<=a[j] && a[j]<=29)
    {
        if (a[j]>=10)
        {   if (a[j+1]>=0)
                a[j+1]=a[j+1]+a[j]/10;
            else
                a[j+1]=a[j]/10;
            a[j]=a[j]%10;
        }
        ++j;
    }
}
int main()
{
    int n,b[100];
    cin>>n;
    memset(b,-1,sizeof(b));
    b[1]=3;
    if (n==1) cout<<3<<endl;
    else {
    for (int j1=1;j1<=n-1;++j1)
    {
        cheng(b);
    }
    for (int j1=j-1;j1>=1;--j1)
        cout<<b[j1];
    cout<<endl;
    }
}