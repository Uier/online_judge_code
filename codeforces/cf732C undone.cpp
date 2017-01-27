#include <iostream>
using namespace std;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	long long b, d, s, ans=2000000000000000000, ans1=0, ans2=0, ans3=0;
	cin >> b >> d >> s;
//	if ( b >= d && b >= s )
		ans1 = (b-1-s)+(b-1-d);
//	else if ( d >= b && d >= s )
		ans2 = (d-1-b)+(d-1-s);
//	else if ( s >= b && s >= d )
		ans3 = (s-1-b)+(s-1-d);
	if ( ans1 >= 0 )
		ans = min(ans,ans1);
	if ( ans2 >= 0 )
		ans = min(ans,ans2);
	if ( ans3 >= 0 )
		ans = min(ans,ans3);
	if ( ans == 2000000000000000000 )
		ans = 0;
	cout << ans << '\n';
	return 0;
}

