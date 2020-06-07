#include <iostream>
#include  <string>
#include <queue>
#include <iomanip>
using namespace std;
int main()
{
    double a[4][4];
    double ii[4][4]={0};
    ii[1][1]=1;ii[2][2]=1;ii[3][3]=1;
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j)
        {
            cin>>a[i][j];
        }
    for (int i=2;i<=3;++i)
    {
        int k=a[i][1];
        for (int j=1;j<=3;++j)
        {
            a[i][j]=a[i][j]*a[1][1]-a[1][j]*k;
            ii[i    ][j]=ii[i][j]*a[1][1]-ii[1][j]*k;
        }//将第一列主元位置下的数全部变成0
    }
    if (a[3][2]!=0)
    {
    a[3][3]=a[3][3]*a[2][2]-a[2][3]*a[3][2];
    for (int i=1;i<=3;++i)
    {
        ii[3][i]=ii[3][i]*a[2][2]-ii[2][i]*a[3][2];
    }//简化阶梯形
    a[3][2]=0;
    }
    for (int j=1;j<=3;++j)
    {
        a[2][j]=a[2][j]*a[3][3]-a[3][j]*a[2][3];
        ii[2][j]=ii[2][j]*a[3][3]-ii[3][j]*a[2][3];
    }
    a[2][3]=0;
    for (int j=1;j<=3;++j)
    {
        //cout<<ii[1][j]<<" "<<ii[3][j]<<endl;
        ii[1][j]=ii[1][j]*a[3][3]-ii[3][j]*a[1][3];
        a[1][j]=a[1][j]*a[3][3]-a[3][j]*a[1][3];
    }//第三列搞定
    for (int j=1;j<=3;++j)
    {
        ii[1][j]=ii[1][j]*a[2][2]-ii[2][j]*a[1][2];
        a[1][j]=a[1][j]*a[2][2]-a[2][j]*a[1][2];
    }
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j)
        {
            ii[i][j]=ii[i][j]/a[i][i];
        }//简化阶梯形
    for (int i=1;i<=3;++i)
    {
        cout<<fixed<<setprecision(2);
        cout<<ii[i][1]<<setw(7)<<ii[i][2]<<setw(7)<<ii[i][3];
        cout<<endl;
    }
}

