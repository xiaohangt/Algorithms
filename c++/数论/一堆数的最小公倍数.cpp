#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string,bool> f;
    string a;
    int n,m,answer;
    cin>>n>>m;
    answer=n;
    for (int i=1;i<=n;++i)
    {
        cin>>a;
        f[a]=0;
    }
    for (int i=1;i<=m;++i)
    {
        cin>>a;
        if (f[a]==0) --answer;
        f[a]=1;
    }
    cout<<endl<<answer<<endl;
}
