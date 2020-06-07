//记住汉字的int是负数即可
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin>>n;
    getchar();
    for (int i=1;i<=n;++i)
    {
        string a;
        getline(cin,a);
        int p=0;
        for (int j=0;j<=a.length()-1;++j)
        {
            if (a[j]<0)
               {
                   ++p;
                   //cout<<a[j]<<" ";
               }
        }
        cout<<p/2<<endl;
    }
}
