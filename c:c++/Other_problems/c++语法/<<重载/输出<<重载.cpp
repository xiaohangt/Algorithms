#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;
#define myendl '\n'
#define myhex string("myhex")
#define myfixed string("myfixed")
#define mypres(n) k(n)


int shu=0;
bool h=false,f=false;
class k
{
public:
    int pres;
    k(int a):pres(a){};
};
class sss
{
public:
    sss &operator << (const char * a )
    {
        if (!h && !f) printf("%s",a);
        return *this;
    }
    sss &operator << (char a)
    {
        printf("%c",a);
        return *this;
    }
    sss &operator << (string a)
    {
        if (a==string("myfixed"))
        {
            f=true;
        }
        else if (a==string ("myhex"))
        {
            h=true;
        }
        return *this;
    }
    sss &operator << (k kk)
    {
        shu=kk.pres;
        return *this;
    }
    sss &operator << (double a)
    {
        if (f)
        {
            printf("%.*lf",shu,a);
        }
        else
        {
            if (shu!=0)
                printf("%.*g",shu,a);
            else
            {
                printf("%.lf",a);
            }
        }
        return *this;
    }
    sss &operator << (int a)
    {
        if (h) printf("%x",a);
        else printf("%d",a);
        return *this;
    }
};
sss myout;

int main()

{
    
    const char *test1 = "Test char";
    
    
    
    myout << test1 << myendl;
    
    myout << test1[0]<< myendl;
    
    
    
    double e = 6.12345;
    
    int pres = 1;
    
    myout << mypres(pres*2);//setprecision(2),2位有效数字
    
    myout << e << myendl;
    
    myout << myfixed ;//改为定点输出，即2位小数
    
    myout << e << myendl;
    
    
    
    int d=15;
    
    myout << d << myendl;
    
    myout << myhex << d << myendl;
    
    
    
}

