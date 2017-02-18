#include<iostream>
using namespace std;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long odd[2]={0,0}, even[2]={0,0}, x;
	for ( int i=0; i<n; i++ ) {
		cin >> x;
		odd[1] = max(odd[0],even[0]+x);
		even[1] = max(even[0],odd[0]-x);
		odd[0] = odd[1];
		even[0] = even[1];
	}
	cout << max(even[0],odd[0]) << '\n';
}

