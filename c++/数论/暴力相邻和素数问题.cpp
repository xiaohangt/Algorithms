

#include <iostream>
using namespace std;
 int a[30],f[30],n;
 int p[38],m=0;
 void aom(int i)
 {
     if (i==n+1)
     {
         if (p[a[n]+1]==1)
         {
             for (int k=1;k<=n;++k)
             {
                 if (k==n) cout<<a[k];
                 else cout<<a[k]<<' ';
             }
             cout<<endl;
         }
     }
     for (int j=2;j<=n;++j)
     {
        if ((p[j+a[i-1]]==1) && (f[j]!=1))
          {
            a[i]=j;
            f[j]=1;
            aom(i+1);
            f[j]=0;//关键一步
          }
      }
     
     

 }
int main() {
    p[1]=1;p[2]=1;p[3]=1;p[5]=1;
    p[7]=1;p[11]=1;p[13]=1;p[17]=1;p[19]=1;p[23]=1;p[29]=1;p[31]=1;p[37]=1;
    f[1]=1;a[1]=1;a[n+1]=1;
    while (cin>>n)
    {
      
      ++m;
      cout<<"Case "<<m<<":"<<endl;
      aom(2);
      cout<<endl;
    }

}
