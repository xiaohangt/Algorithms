/*
主函数的形式如下：
int main()
{
    Number n(1);
    n.add(2).sub(3).add(4);
    n.print();
    return 0;
}        //过程为1+2-3+4 结果输出4

编写一个Number类，包括构造函数，add（加法），sub（减法），print（输出）
主要不知道怎么可以进行链式调用n.add(2).sub(3).add(4)怎么实现。
*****n.add(2)返回n本身，然后返回值又可以.sub*/


#include <cstdio>
using std::printf;

class Number
{
public:
    Number(int n) : value(n) {}
    Number &add(int val)
    {
        value += val;
        return *this;
    }
    Number &sub(int val)
    {
        return add(-val);
    }
    void print() const
    {
        printf("%d\n", value);
    }
private:
    int value;
};

int main()
{
    Number n(1);
    n.add(2).sub(3).add(4);
    n.print();
    return 0;
}