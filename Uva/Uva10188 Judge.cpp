#include <iostream>
#include <stack>
using namespace std;
int n, m;
string sin[102], sout[102];
stack<char> num;
stack<char> nnum;
bool ac() {
	for ( int i=0; i<n; i++ )
		if ( sin[i] != sout[i] )
			return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x=0;
	while ( cin >> n ) {
		if ( n == 0 )
			break;
		x++;
		while ( !num.empty() )
			num.pop();
		while ( !nnum.empty() )
			nnum.pop();
		getline(cin,sin[0]);
		for ( int i=0; i<n; i++ ) {
			getline(cin,sin[i]);
			for ( int j=0; j<sin[i].size(); j++ ) {
				if ( sin[i][j] >= '0' && sin[i][j] <= '9' )
					nnum.push(sin[i][j]);
				else if ( sin[i][j] != ' ' )
					num.push(sin[i][j]);
			}
		}
		cin >> m;
		getline(cin,sout[0]);
		for ( int i=0; i<m; i++ )
			getline(cin,sout[i]);
		cout << "Run #" << x << ": ";
		if ( n == m && ac() )
			cout << "Accepted" << '\n';
		else {
			bool ans=true;
			bool ans2=true;
			for ( int i=m-1; i>=0; i-- )
				for ( int j=sout[i].size()-1; j>=0; j-- ) {
					if ( sout[i][j] >= '0' && sout[i][j] <= '9' && (nnum.empty()||sout[i][j] != nnum.top()) )
						ans2 = false;
					else if ( sout[i][j] >= '0' && sout[i][j] <= '9' )
						nnum.pop();
					else if ( sout[i][j] != ' ' && (num.empty()||sout[i][j]!=num.top()) )
						ans = false;
					else if ( sout[i][j] != ' ' )
						num.pop();
				}
			if ( (ans && num.empty()) && (ans2&&nnum.empty()) )
				cout << "Presentation Error" << '\n';
			else if ( ans2&&nnum.empty() )
				cout << "Presentation Error" << '\n';
			else
				cout << "Wrong Answer" << '\n';
		}
	}
	return 0;
}

