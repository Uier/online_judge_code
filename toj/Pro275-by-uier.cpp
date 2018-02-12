#include <iostream>
#include <queue>
using namespace std;
priority_queue<double> L;
priority_queue<double,vector<double>,greater<double>> H;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double n, x;
	cin >> n;
	for ( int i=1; i<=n; ++i ) {
		cin >> x;
		if ( L.empty() || L.top() > x )	L.push(x);
		else	H.push(x);
		if ( i%2 == 0 ) {
			if ( L.size() > H.size() ) {
				H.push(L.top());
				L.pop();
			} else if ( L.size() < H.size() ) {
				L.push(H.top());
				H.pop();
			}
			printf("%.6lf\n", (L.top()+H.top())/2);
		}
		else if ( L.size() < H.size() )
			printf("%.6lf\n", H.top());
		else
			printf("%.6lf\n", L.top());
	}
	return 0;
}

