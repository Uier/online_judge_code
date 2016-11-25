#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int> S;
queue<int> Q;
priority_queue<int> P;
int n, a, b;
bool s, q, p;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n ) {
		while ( !S.empty() )	S.pop();
		while ( !Q.empty() )	Q.pop();
		while ( !P.empty() )	P.pop();
		s = q = p = true;
		while ( n-- ) {
			cin >> a >> b;
			if ( a == 1 ) {
				S.push(b);
				Q.push(b);
				P.push(b);
			}	
			else {
				if ( s ) {
					if ( S.empty() || S.top() != b ) {
						s = 0;
						S.pop();
					}
					else if ( !S.empty() )	S.pop();
				}
				if ( q ) {
					if ( Q.empty() || Q.front() != b ) {
						q = 0;
						Q.pop();
					}	
					else if ( !Q.empty() )	Q.pop();
				}
				if ( p ) {
					if ( P.empty() || P.top() != b ) {
						p = 0;
						P.pop();	
					}
					else if ( !P.empty() )	P.pop();
				}
			}
		}
		if ( (s && q) || (s && p) || (q && p) )
			cout << "not sure\n";
		else if ( s )
			cout << "stack\n";
		else if ( q )
			cout << "queue\n";
		else if ( p )
			cout << "priority queue\n";
		else
			cout << "impossible\n";
	}
	return 0;
}

