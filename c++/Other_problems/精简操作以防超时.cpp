//Counts the occurrences of the largest number.
//Another way to solve the problem is to maintain two variables, max and count. max stores the current max number, and count stores its occurrences. Initially, assign the first number to max and 1 to count. Compare each subsequent number with max. If the number is greater than max, assign it to max and reset count to 1. If the number is equal to max, increment count by 1
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int m,big=-10000,p=0;
        scanf("%d",&m);
        int a[1000];
        for (int j=1;j<=m;++j)
        {
            scanf("%d",&a[j]);
            if (big<a[j]) {big=a[j];p=1;}
            else if (big==a[j]) ++p;
        }
        printf("%d %d\n",big,p);
    }
}