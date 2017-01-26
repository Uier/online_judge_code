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
	// �s����C push_back�s�J���| make_pair�j�v�� 
	return 0;
}


// g[n][n];
// if i ��j�s�b g[i][j]=1 (�v��) 
// else g[i][j]=0 (or��L)
// -------------------------------
// @Breadth First Search
// �g�L1�����F�����I �ٳo��ӳ��I�Z����1 �H������
// youtube(Breadth First Search Algorithm)
// �̷Ӹ��|���ק⳻�I����(�Z��1���Ƥ@�_ �H������) 
// 1.��_�I��Jqueue status
// 2.���I�s�������I��J(�C���Z����+1) 
// �Y�S�� pop �Nbool�]�w���w���L 
// ------------------------------- 
// @Depth First Search
// ����S�����A��^�_�I 
// �̧ǩ�JStack status 

typedef long long ll;
bool used[100]; 			// �P�_�O�_�����L�����|
vector<int> V[100]; 		//  V[100][ ��]
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	while ( m-- )
	{
		cin >> a >> b;
		V[a].push_back(b);	 			// Ex:(1) a=1 b=2 (2) a=2 b=3 (3) a=1 b=4 �� 
	}									//     V[1][0]=2 , V[2][0]=3 , V[1][1]=4;
	//Breadth First Search
	queue<int> rd;
	rd.push(1); 						// rd.push(��_�l�s��,���D�ػݨD)
	memset(used, 0, sizeof(used)); 		// ��l��
	used[1] = true;					    // �_�I used[�_�l�s����W�W�檺�@��]
	while ( !rd.empty() )
	{
		int j=rd.front(); 				// (1) ��line.56 
		rd.pop();
	    cout << j << ' ';			    //�L�X���| 
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
	memset(used,0,sizeof(used));		 // ��l�� 
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


// ���j�gDepth First Search
bool used[100];				 // �P�_�O�_�����L�����|
vector<int> V[100];

void dfs(int n)				 // n = �_�I 
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

