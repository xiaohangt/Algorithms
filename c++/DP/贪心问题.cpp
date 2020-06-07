#include<iostream>
using namespace std;
long long minx;
void oper(long long n,long long temp)
{
    if(minx>temp)
    {
        if(n==1)minx=temp;
        else
            {
            if(n%2==1)
            {
                oper(n+1,temp+1);
                oper(n-1,temp+1);
            }
            else
            {
                oper(n/2,temp+1);
            }
            }
    }
}
int main()
{
    long long n;
    while(cin>>n)
    {
        minx=n;
        oper(n,0);
        cout<<minx<<endl;
    }
    return 0;
}