#include<iostream>
#include<vector>
#include<queue>
#include"memory.h"
using namespace std;
bool used[10050];
vector<int> V[820];
int main()
{
	int n, m, a, b;
	while( cin >> n >> m )
	{
		for ( int i=1; i<=n; i++ )  // 注意這裡要初始化!!! 
			V[i].clear();
		while ( m-- )
		{
			cin >> a >> b;
			V[a].push_back(b);
		}
	    int q1, q2, flag=0;
	    cin >> q1 >> q2;
		queue<int> rd;
		rd.push(q1);
		memset( used, 0, sizeof(used) );
		used[q1] = true;
		while ( !rd.empty() )
		{
			int k=rd.front();
			rd.pop();
			if ( k == q2 )
				flag=1;
			for ( int e : V[k] )
			{
				if ( !used[e] )
				{
					used[e] = true; 
					rd.push(e);
				}
			}
		}
		if ( flag )
			cout << "Yes!!!" << endl;
		else
			cout << "No!!!" << endl;
	}
	return 0;
}

