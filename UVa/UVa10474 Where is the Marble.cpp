#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
int main()
{

	/*
	set multiset 不能尋找值的位址################# 
	multiset<int> s;
	int n, q, i=1;
	while ( cin >> n >> q )
	{
		if ( n == 0 || q == 0 )
			break;
		while ( n-- )
		{
			int a;
			cin >> a;
			s.insert(a);
		}
		while ( q-- )
		{
			cout << "CASE# " << i << ":\n";
			int a;
			cin >> a;
			if ( s.find(a) == s.end() )
				cout << a << " not found\n";
			else
			{
				int tp=s.lower_bound(a);
				cout<<tp<<endl;
				int b=*lower_bound(s.begin(), s.end(), a);
				cout << a << " found at " << b << '\n';
			}
		}
		s.clear();
		i++;
	}
	*/ 
//	########	V	E	C	T	O	R	########
	
	vector<int> v;
	int n, q, i=1;
	while ( cin >> n >> q )
	{
		if ( n == 0 && q == 0 )
			break;
		while ( n-- )
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		cout << "CASE# " << i << ":\n";
		while ( q-- )
		{
			int a;
			cin >> a;
			int b = lower_bound(v.begin(), v.end(), a) - v.begin();
			if ( v[b] == a )
				cout << a << " found at " << b << '\n';
			else
				cout << a << " not found\n";
		}
		v.clear();
		i++;
	}
	
	/*
	
		########	一般陣列	######## 
	
	int m[10001]={0}, n, q, x=1;
	while ( cin >> n >> q )
	{
		if ( n == 0 && q == 0 )
			break;
		for ( int i=0; i<n; i++ )
			cin >> m[i];
		sort(m, m+n);
		cout << "CASE# " << x << ":\n";
		while ( q-- )
		{
			int a;
			cin >> a;
			int b=lower_bound(m, m+n, a)-m;
			if ( m[b] == a )
				cout << a << " found at " << b+1 << '\n';
			else
				cout << a << " not found\n";
		}
		for ( int i=0; i<n; i++ )
			m[i] = 0;
		x++;
	}*/
	return 0;
}

