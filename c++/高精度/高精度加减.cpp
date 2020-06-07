#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;
int an[18]={0},ax=0,bx=0;
int wei=0;
void jia(int a[],int b[])//高精度加法
{
    int jin[18]={0};
    int i=1;
    while (i<=ax || i<=bx)
    {
        jin[i]=(a[i]+b[i])/10;
        an[i]=(jin[i-1]+a[i]+b[i])%10;
        ++i;++wei;
        if ((i>ax && i>bx) && jin[i-1]>0) {an[i]=jin[i-1];++wei;}
    }
}
void jian(int a[],int b[])//高精度减法（前大后小）
{
    int tui[18]={0};
    int i=1;
    while (i<=ax || i<=bx)
    {
        if (a[i]+tui[i-1]<b[i])
        {
            tui[i]=-1;
            an[i]=10+(a[i]-b[i]+tui[i-1]);
        }
        else
        {
            an[i]=a[i]-b[i]+tui[i-1];
        }
        ++i;
        ++wei;
    }
    while (an[wei]==0) --wei;
}
int main()
{
    int a1[18]={0},b1[18]={0};
    string k;
    while (getline(cin,k))
    {
        ax=0;bx=0;wei=0;
        memset(a1,0,sizeof(a1));
        memset(b1,0,sizeof(b1));
        memset(an,0,sizeof(an));
        int ji=0;
        bool p=false;
        char f1='+',f2='+';
        for (int i=k.length()-1;i>=0;--i)
        {
            if ('0'<=k[i] && k[i]<='9')
            {
                ++ji;
                if (p==false) {b1[ji]=int(k[i]-'0');++bx;}
                else
                {
                    a1[ji]=int(k[i]-'0');
                    ++ax;
                }
            }
            else
            {
                if (k[i]==' ') { p=true; ji=0;}
                if (k[i]=='-')
                {
                    if (i==0) f1='-';
                    else f2='-';
                }
            }
        }//数据处理
        
        if ((f1!='-' && f2!='-') || (f1=='-'&& f2=='-'))
        {
            if (f1=='-') cout<<"-";
            jia(a1,b1);
            for (int k1=wei;k1>=1;--k1) cout<<an[k1];
            cout<<endl;
        }
        else
        {
            bool pan=1;//前面的数a1大就为1
            if (ax==bx)
                while (ax>=1)
                {
                    if (a1[ax]<b1[ax])
                    {
                        pan=0;
                        break;
                    }
                    else
                    {
                    if (a1[ax]==b1[ax])
                    {
                        --ax;
                    }
                    else break;
                    }
                }
            else
            {
                if (ax<bx) pan=0;
            }//检查两个数的大小；
            
            if (pan==1)
            {
                jian(a1,b1);
                
                if (f1=='-' && wei>=1) cout<<"-";
                else if (wei<1) cout<<"0";
                for (int k1=wei;k1>=1;--k1) cout<<an[k1];
                cout<<endl;
            }
            else
            {
                if (f2=='-') cout<<"-";
                jian(b1,a1);
                for (int k1=wei;k1>=1;--k1) cout<<an[k1];
                cout<<endl;
            }
        }
        k="";
    }
}