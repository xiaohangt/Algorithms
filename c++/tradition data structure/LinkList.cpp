#include<iostream>
#include<stdlib.h>

using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> * next; 
};

template<class DataType>
class LinkList;
template<class DataType>
void Union(LinkList<DataType> &A,LinkList<DataType> &B);//A = A ∪B
template<class DataType>
void Cross(LinkList<DataType> &A,LinkList<DataType> &B);//A = A ∩B

template<class DataType>
class LinkList
{
	public:
		LinkList();
		LinkList(DataType a[],int n);
		~LinkList();
		int Length();
		DataType Get(int i);
		int Locate(DataType x);
		void Insert(int i,DataType x);
		DataType Delete(int i);
		void PrintList();
		
		friend void Union<>(LinkList<DataType> &A,LinkList<DataType> &B);
		friend void Cross<>(LinkList<DataType> &A,LinkList<DataType> &B);
	private:
		Node<DataType> * first;
};

template<class DataType>
void Union(LinkList<DataType> &A,LinkList<DataType> &B)//A = A ∪B
{
	...
}

template<class DataType>
void Cross(LinkList<DataType> &A,LinkList<DataType> &B)//A = A ∩B
{
	...
}

int main()
{
	...
}



///// 

template<class DataType>
LinkList<DataType>::LinkList()
{
	first=new Node<DataType>;
	first->next=NULL;
}
//template<class DataType>
//LinkList<DataType>::LinkList(DataType a[],int n)//头插法 
//{
//	first=new Node<DataType>;
//	first->next=NULL;
//	for(int i=0;i<n;i++)
//	{
//		s=new Node<DataType>;
//		s->data=a[i];
//		s->next=first->next;
//		first->next=s;
//	}
//}
template<class DataType>                          
LinkList<DataType>::LinkList(DataType a[],int n)//尾插法
{
	first=new Node<DataType>;
	Node<DataType> * r=first,* s;
	for(int i=0;i<n;i++)
	{
		s=new Node<DataType>;
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}
template<class DataType>
LinkList<DataType>::~LinkList()
{
	while(first!=NULL)
	{
		Node<DataType> * q=first;
		first=first->next;
		delete q;
	}
}
template<class DataType>
int LinkList<DataType>::Length()
{
	Node<DataType> * p=first->next;
	int count=0;
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	return count;
}
template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType> * p=first->next;
	int count=1;
	while(p!=NULL&&count<i)
	{
		p=p->next;
		count++;
	}
	if(p==NULL)throw"位置";
	return p->data;
}
template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType> * p=first->next;
	int count=1;
	while(p!=NULL)
	{
		if(p->data==x)return count;
		p=p->next;
		count++;
	}
	return 0;
}
template<class DataType>
void LinkList<DataType>::Insert(int i,DataType x)
{
	Node<DataType> * p=first;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL)throw"位置";
	Node<DataType> * s=new Node<DataType>;
	s->data=x;
	s->next=p->next;
	p->next=s;
}
template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType> * p=first;
	int count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL||p->next==NULL)throw"位置";
	Node<DataType> * q=p->next;
	DataType x=q->data;
	p->next=q->next;
	delete q;
	return x;
}
template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> * p=first->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}


