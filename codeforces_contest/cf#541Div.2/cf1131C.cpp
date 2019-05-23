#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>
#include <string.h>
#define int long long
#define maxn 101
using namespace std;
typedef pair<int,int> pii;
int arr[maxn];
deque<int> ans;
main() {
	ios::sync_with_stdio(false);
	//   sync_with_YinHsuan(true);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; ++i ) {
		cin >> arr[i];
	}
	sort(arr,arr+n);
	ans.push_back(arr[0]);
	for ( int i=1; i<n; i+=2 ) {
		if ( i <= n-2 ) {
			int _a = max(abs(arr[i]-ans.front()),abs(arr[i+1]-ans.back()));
			int _b = max(abs(arr[i+1]-ans.front()),abs(arr[i]-ans.back()));
			if ( _a > _b ) {
				ans.push_front(arr[i+1]);
				ans.push_back(arr[i]);
			} else {
				ans.push_front(arr[i]);
				ans.push_back(arr[i+1]);
			}
		} else {
			ans.push_back(arr[i]);
		}
	}
	while ( !ans.empty() ) {
		cout << ans.front() << ' ';
		ans.pop_front();
	}
	return 0;
}

