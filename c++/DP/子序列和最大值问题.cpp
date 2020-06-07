
#include <iostream>
using namespace std;


//优化子序列和最大问题关键：将为负子序列去掉
//细节：对于位置记录需特殊考虑
int main() {
    int n,m,sum,bests,beste,st;
    int f[100000];
    long best;
    cin>>m;
    for(int i=1;i<=m;++i)
    {
         cin>>n;
        bests=1;st=1;beste=1;sum=0;best=-10000;
       for (int j=1;j<=n;++j)
       {
           cin>>f[j];
           sum=sum+f[j];
           if (best<sum)
           {
               bests=st;
               best=sum;
               beste=j;
           }
           if (sum<0)
           {
               st=j+1;
               sum=0;
           }
           
          }
        if (i==m) cout<<"Case "<<i<<":"<<endl<<best<<" "<<bests<<" "<<beste<<endl;
        else cout<<"Case "<<i<<":"<<endl<<best<<" "<<bests<<" "<<beste<<endl<<endl;
    }
}
