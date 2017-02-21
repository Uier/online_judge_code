#include<iostream>
using namespace std;
#define maxn 100
int par[maxn],n;
void init()
{
	for(int i=1;i<n;++i) par[i]=i;
}
int find(int x)
{
	//return par[x] = par[x]==x?x:find(par[x]);
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}
void U(int x,int y)
{
	par[find(x)]=find(y);
	/*
	x=find(x);
	y=find(y);
	par[x]=y;
	//par[y]=x;*/
}
int main()
{
	return 0;
}

