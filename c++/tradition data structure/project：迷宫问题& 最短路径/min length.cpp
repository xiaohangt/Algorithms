#include<iostream>
using namespace std;

const int QueueSize=1000;


struct qnode
{
 int j,f;
};

template<class DataType>
class CirQueue
{
 public:
  CirQueue(){front=rear=QueueSize-1;}
  ~CirQueue(){}
  void EnQueue(DataType x);
  DataType DeQueue();
  DataType GetQueue();
  int Empty(){return front==rear?1:0;}
  void print()
  {
    for (int i=front;i<=rear;++i)
      cout<<data[i].j<<' '<<data[i].f<<endl;
    cout<<endl;
  }
// private:
  DataType data[QueueSize];
  int front,rear;
};
template<class DataType>
void CirQueue<DataType>::EnQueue(DataType x)
{
 if((rear+1)%QueueSize==front)throw"ÉÏÒç";
 rear=(rear+1)%QueueSize;
 data[rear]=x;
}
template<class DataType>
DataType CirQueue<DataType>::DeQueue()
{
 if(rear==front)throw"ÏÂÒç";
 front=(front+1)%QueueSize;
 return data[front];
}
template<class DataType>
DataType CirQueue<DataType>::GetQueue()
{
 if(rear==front)throw"ÏÂÒç";
 return data[(front+1)%QueueSize];
}


int main()
{
 int a[5][5]={
 {-1,6,4,-1,3},
 {-1,-1,4,-1,-1},
 {-1,-1,-1,-1,-1},
 {15,5,10,-1,7},
 {-1,2,-1,-1,-1,}
 };
 int r[5],p[5],j,s,f;
 for(int i=0;i<5;++i) 
 { 
  a[i][i]=-1;
  r[i]=10000;p[i]=-1;
 }
 CirQueue<qnode> q;
 qnode w;
 w.j=3;w.f=-1;
 q.EnQueue(w);
 r[3]=0;
 while (!q.Empty())
 {
  w=q.DeQueue();s=w.j;
  for (int j=0;j<5;++j)
  {
   if (a[s][j]!=-1)
   {
   if (r[s]+a[s][j]<r[j] )
   {
    w.j=j;w.f=s;
    q.EnQueue(w);
    r[j]=r[s]+a[s][j];
    p[j]=q.data[q.rear].j;
    q.print();
   
   }
  }
 }
}
 s=0;
 for (int i=0;i<5;++i)
 {
  if (r[s]>r[i] && r[i]!=0) s=i;
  //cout<<p[i]<<endl;
 } 
  int shortest=r[s];
  j=p[s];
  int path[5],k=4;
  path[k]=q.data[j].j;k--;
  while (q.data[j].f!=-1)
  {
   j=q.data[j].f;
   path[k]=q.data[j].j;
   --k;
  }
  
  for (int t=k;t<5;++t) 
  {
    cout<<path[k]<<' ';
    if (path[k]==3) break;
  }
 cout<<endl;
 cout<<shortest<<endl;
}