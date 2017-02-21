#include<iostream>
#include<vector>
#include<queue>
#include"memory.h"
using namespace std;


typedef pair<int,int> pii;
vector<pii> V[10];
int main()
{
	int m,s,e,w;
	cin >> m;
	while ( m-- )
	{
		cin >>s >> e >> w;
		V[s].push_back(make_pair(e,w));
	//	V[s].push_back({e,w});
	}
	// 連結串列 push_back存入路徑 make_pair綁權重 
	return 0;
}


// g[n][n];
// if i →j存在 g[i][j]=1 (權重) 
// else g[i][j]=0 (or其他)
// -------------------------------
// @Breadth First Search
// 經過1條邊到達的頂點 稱這兩個頂點距離為1 以此類推
// youtube(Breadth First Search Algorithm)
// 依照路徑長度把頂點推類(距離1的排一起 以此類推) 
// 1.把起點放入queue status
// 2.把點連接的頂點放入(每次距離都+1) 
// 若沒路 pop 將bool設定為已走過 
// ------------------------------- 
// @Depth First Search
// 走到沒有路再返回起點 
// 依序放入Stack status 

typedef long long ll;
bool used[100]; 			// 判斷是否為走過的路徑
vector<int> V[100]; 		//  V[100][ ∞]
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	while ( m-- )
	{
		cin >> a >> b;
		V[a].push_back(b);	 			// Ex:(1) a=1 b=2 (2) a=2 b=3 (3) a=1 b=4 ↓ 
	}									//     V[1][0]=2 , V[2][0]=3 , V[1][1]=4;
	//Breadth First Search
	queue<int> rd;
	rd.push(1); 						// rd.push(放起始編號,看題目需求)
	memset(used, 0, sizeof(used)); 		// 初始化
	used[1] = true;					    // 起點 used[起始編號跟上上行的一樣]
	while ( !rd.empty() )
	{
		int j=rd.front(); 				// (1) →line.56 
		rd.pop();
	    cout << j << ' ';			    //印出路徑 
		for ( int e : V[j] )            // (1) e=V[1][0] ,  (2) e=V[1][1]  (vector) 
		{
			if ( !used[e] )
			{
				used[e] = true; 
				rd.push(e);
			}
		}
	}
	return 0;
}

	//Depth First Search
	stack<int> s;
	s.push(0);
	memset(used,0,sizeof(used));		 // 初始化 
	used[0]=true;
	while ( !s.empty() )
	{
		int k = s.top();
		s.pop();
		cout << k << ' ';
		used[k] = true;
		for ( int e : V[k] )
		{
			if ( !used[e] )
			{
				used[e] = true; 
				s.push(e);
			}
		}
	}
}


// --------------------------


// 遞迴寫Depth First Search
bool used[100];				 // 判斷是否為走過的路徑
vector<int> V[100];

void dfs(int n)				 // n = 起點 
{
	cout << n << ' ';
	for ( int e : V[n] )
	{
		if ( !used[e] )
		{
			used[e] = true;
			dfs(e);
		}
	}
}

