#include <iostream>
#include <map>
using namespace std;
int main() {
	int n, m, p;
	long long ans=0;
	map<string,int> hay;
	string s;
	cin >> n >> m;
	while ( n-- ) {
		cin >> s >> p;
		hay[s] = p;
	}
	while ( m-- ) {
		while ( cin >> s && s != "." )
			if ( hay[s] > 0 )
				ans += hay[s];
		cout << ans << '\n';
		ans = 0;
	}
	return 0;	
}
//
//	Fail 
//         by uier 2016/8/28
//
//#include <iostream>
//#include <string>
//using namespace std;
//struct hay {
//	string w;
//	int p;
//} a[1005];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n, m;
//	cin >> n >> m;
//	for ( int i=0; i<n; i++ )
//		cin >> a[i].w >> a[i].p;
//	string s;
//	long long ans=0;
//	getline(cin,s);
//	while ( getline(cin,s) ) {
//		if ( s.find(".") != string::npos ) {
//			cout << ans << '\n';
//			m--;
//			if ( m == 0 )
//				break;
//			ans = 0;
//		}
//		for ( int i=0; i<n; i++ ){
//			while ( s.find(a[i].w) != string::npos ) {
//				s.replace(s.find(a[i].w),a[i].w.size(),"");
//				ans += a[i].p;
//			}
//		}
//	}
//	return 0;
//}

