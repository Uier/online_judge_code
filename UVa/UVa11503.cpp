#include <iostream>
#include <map>
using namespace std;
map<string,int> F;
int A[200005];
int P[200005];
int find(int x) {
	return ((P[x]==x) ? x : (P[x]=find(P[x])));
}
void U(int x, int y) {
	P[find(x)] = find(y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		int m = 1;
		F.clear();
		for ( int i=1; i<=n*2; i++ ) {
			A[i] = 1;
			P[i] = i;
		}
		for ( int i=0; i<n; i++ ) {
			string a, b;
			cin >> a >> b;
			if ( !F[a] )	F[a] = m++;
			if ( !F[b] )	F[b] = m++;
			if ( find(F[a]) != find(F[b]) ) {
				int temp = A[find(F[a])];
				A[find(F[a])] += A[find(F[b])];
				A[find(F[b])] += temp;
				U(F[a],F[b]);
			}
			cout << A[find(F[a])] << '\n';
		}
	}
	return 0;
}

