#include<bits/stdc++.h>
using namespace std;
int v=0;
string bt[30];
void make(string x) {
	for ( int i=0; i<4; i++ ) {
		bt[v++] = x;
//		cout << x << '\n';
		for ( int j=2; j<5; j++ )
			swap(x[j],x[j+1]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	bool ans;
	cin >> t;
	while ( t-- ) {
		v = 0;
		ans = false;
		string a, b;
		cin >> a >> b;
		for ( int i=0; i<30; i++ )	bt[i] = "";
		string c = a;
		make(c);
		swap(c[0],c[1]);	swap(c[2],c[3]);	swap(c[4],c[5]);
		make(c);
		string d = a;
		swap(d[0],d[2]);	swap(d[1],d[4]);	swap(d[3],d[5]);
		make(d);
		swap(d[0],d[1]);	swap(d[2],d[3]);	swap(d[4],d[5]);
		make(d);
		string e = a;
		swap(e[0],e[3]);	swap(e[1],e[5]);	swap(e[2],e[4]);
		make(e);
		swap(e[0],e[1]);	swap(e[2],e[3]);	swap(e[4],e[5]);
		make(e);
		for ( int i=0; i<24; i++ )
			if ( bt[i] == b )
				ans = true;
		if ( ans )	cout << "Equal\n";
		else	cout << "Not Equal\n";
	}
	return 0;
}

