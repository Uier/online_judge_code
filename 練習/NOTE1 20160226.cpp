#include<bits/stdc++.h>

using namespace std;

struct data{
	int x,y;
}d[100];

/*
bool operator < (data a,data b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;	
}
*/

bool c123(data a,data b)
{
	if (a.x!=b.x)	return a.x<b.x;
	return a.y<b.y;
}
int main()
{
//	dp **
//	背包 ** 
//	queue *** 
//	deque ***
//	priority_queue ***
//	disjoint set *
//  區間內質數 *
//	Uva 10035
//	Uva 10008
//	Uva 10222
//	Uva 11332
//	Uva 10295
//	Uva 10340 ( O(n) )
//	Uva 10188
	d[0]={5,2};
	d[1]={4,8};
	d[2]={4,6};
	d[3]={6,5};
	sort(d,d+4,c123);
	for(int i=0;i<4;++i)
	{
		cout<<d[i].x<<' '<<d[i].y<<endl;
	}
	map<int ,int> mp;
	mp[5]=1;
	mp[4]=2;
	int s;cin>>s;
	cout<<mp[s]<<endl;
	return 0;
}

