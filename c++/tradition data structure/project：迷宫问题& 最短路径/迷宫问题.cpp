#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int qi[100][100];
const int size=100;
struct point
{
	int a,b;
};

class stack
{
	public:
		stack()
		{
			an[0].a=0;
			an[0].b=0;
			top=-1;
		}
		void push(int x,int y)
		{
			++top;
			an[top].a=x;
			an[top].b=y;
		}
		point pop()
		{
			top--;
			return an[top];
		}
		void print()
		{
			for (int i=0;i<=top;++i) cout<<an[i].a<<' '<<an[i].b<<endl;
		}
		int gettop() {return top;}
	private:
		point an[1000];
		int top;
};

class queue
{
public:
	queue(){rear=0;first=0;}
	void enqueue(int x,int y)
	{
		++rear;
		an[rear].a=x;
		an[rear].b=y;
	}
	point dequeue()
	{
		++first;
		return an[first-1];
	}
	bool empty(){if (rear==first) return 1;return 0;}
private:
	int rear,first;
	point an[1000];
};



//一：深搜(找到路就退出)
stack danswer;//此栈为存储答案的栈
int n=1;
void dfs(int x,int y)
{
	danswer.push(x,y);
	qi[x][y]=1;
	if (x+y==17 || (x==8 && y==8)) 
	{	
		cout<<"answer "<<n<<':'<<endl;
		++n;
		danswer.print();
		cout<<9<<' '<<9<<endl;
		qi[x][y]=2;
		return;
	}//找到目的地，标记已经找到路，并且直接输出即可
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j)
		{
			int a=i,b=j;
			if (a==2) a=-1;
			if (b==2) b=-1;
			if (!qi[x+a][y+b]) 
				{
					dfs(x+a,y+b);
					if (qi[x+a][y+b]==1) qi[x+a][y+b]=0;
					danswer.pop();
				}
		}
	//深搜:有待改进，稍显冗余
}

//二：宽搜(找到最短路径)

void bfs(int x,int y)
{

}


int main()
{
//1.棋盘初始化

	for (int i=0;i<=10;++i)
		for (int j=0;j<=10;++j)
		{
			qi[i][j]=1;
		}
	
	qi[1][1]=0;
	qi[2][2]=0;qi[2][3]=0;qi[3][4]=0;
	qi[4][5]=0;qi[5][5]=0;qi[6][5]=0;
	qi[7][5]=0;qi[8][5]=0;qi[9][5]=0;
	qi[9][6]=0;qi[9][7]=0;qi[9][8]=0;qi[9][9]=0;
	qi[6][6]=0;qi[6][7]=0;qi[7][8]=0;qi[8][9]=0;
	qi[1][4]=0;qi[1][5]=0;qi[1][6]=0;qi[1][7]=0;qi[1][8]=0;qi[1][9]=0;
	qi[6][4]=0;qi[6][3]=0;qi[7][3]=0;qi[8][3]=0;qi[9][3]=0;
	qi[9][4]=0;qi[9][5]=0;

	for (int i=0;i<=10;++i)
	{
		for (int j=0;j<=10;++j)
		{
			cout<<qi[i][j]<<' ';
		}
		cout<<endl;
	}
//2.深搜找路
	dfs(1,1);
//3.宽搜找路
	
}