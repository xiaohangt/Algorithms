#include<iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
const int maxsize=100;

template <class datatype>
class F
{
	public:
		F();
		F(datatype f[], int l);
		~F();
		void set(datatype *f , int l);
		void show();
		void reverse();
		void insert(int n, datatype k);
		int getlength();


	private:
		datatype *a;
		int length;
};

//无参构造函数
template <class datatype>
F<datatype>::F()
{
	length=0;
}


//有参构造函数
/*template <class datatype>
F<datatype>::F(datatype f[], int l)
{
	a=f;
	length=l;
}*/


//析构函数
template <class datatype>
F<datatype>::~F()
{

}

template <class datatype>
void F<datatype>::set(datatype * aa,int l)
{
	length=l;
	//for (int i=0;i<length;++i) a[i]=aa[i];
	a=aa;
}

template <class datatype>
void F<datatype>::show()
{
	for (int i=0;i<length-1;++i) 
	{
		cout<<a[i]<<' ';
	}
	cout<<a[length-1]<<endl;
}

//逆序输出
template <class datatype>
void F<datatype>::reverse()
{
	/*for (int i=length-1;i>0;--i)
	{
		cout<<a[i]<<' ';
	}
	cout<<a[0]<<endl;*/
	for (int i=0;i<length;++i)
	{
		if (i<length/2) 
		{
			datatype t=a[i];
			a[i]=a[length-1-i];
			a[length-1-i]=t;
		}
		else break;
	}

}

//插入
template <class datatype>
void F<datatype>::insert(int n, datatype k)
{
	++length;
	for (int i=length-1;i>n;--i)
	{
		a[i]=a[i-1];
	}
	a[n]=k;
}

template <class datatype>
int F<datatype>::getlength()
{
	return length;
}

int main()
{
	srand(time(0));
	F<int> List;
	int A[maxsize],B[maxsize],M=10,N=5,num=0;
	for (int i=0;i<M;++i) 
	{
		num= rand()% 10;
		A[i]=num;
	}
	for (int i=0;i<N;++i) 
	{
		num= rand()% 10;
		B[i]=-num;
	}
	List.set(A,M);
	for (int i=0;i<N;++i)
	{
		num= rand()% List.getlength();
		List.insert(num,B[i]);
	}
	List.show();
	List.reverse();
	List.show();
}