#include<iostream>
#include<cstdlib>
using namespace std;
// 改动一：增加函数模板的声明——而这又需要先声明类模板
template <class DT> class SL;
template <class DT>
void sum2(SL<DT> LD,DT &sum);
template<class DT>
class SL
{
	public:
		SL(){L=0;
		}
		SL(DT a[],int n){
			for (int i=0;i<n;i++)
			  data[i]=a[i];
			L=n;  
		}
		~SL(){
		}
		int Length(){
			return L;
		};
		void ins(int i,DT x){
			if (i<1||i>L+1) throw"error";
			int j;
			for (int j=L;j>=i;j--)
			  data[j]=data[j-1];
			 data[i-1]=x;
			 L++; 
		}
		void PL(){
			for (int i=0;i<L;i++)
			   cout<<data[i]<<" ";
			   cout<<endl;
		}
		void RE(){
			DT w;
			for(int i=0;i<=L/2-1;i++)
			     {
			     	w=data[i];
			     	data[i]=data[L-i-1];
			     	data[L-i-1]=w;
				 }
		}
		DT get(int i){
			return data[i];
		}
		friend void sum2<>(SL<DT> LD,DT &sum);
		// 改动二：在函数名后面加上<>，指明它是之前声明的函数 模板 的实例
	private:
	   DT data[150];
	   int L;
};
 template<class DT>
  DT sum1(DT *LD,int n){
  	DT t=0;
  	for(int i=0;i<n;i++){
  		  t=t+LD[i];
	  }
	  return t;
  }
 template<class DT>
  void  sum2(SL<DT> LD,DT &sum){
  	 sum=0;
  	for(int i=0;i<LD.Length();i++){
  		sum+=LD.data[i];
	  }
  }
int main(){
	int a[10],b[10];
	for(int i=0;i<10;i++){
		a[i]=rand()%10;
		b[i]=-rand()%10;
	}
	SL<int> ql(a,10);
	ql.PL();
	for(int i=0;i<10;i++){
		ql.ins((rand()%ql.Length())+1,b[i]);
	}
	ql.PL();
	cout<<sum1(a,10)<<endl;
	int t=0;
	sum2(ql,t);
	cout<<t<<endl;
}
