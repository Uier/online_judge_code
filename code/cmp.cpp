#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct doll {
	int W, H;
} a[5];
bool cmp(doll x, doll y) {
	return (x.H < y.H && x.W < y.W);
}
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	for ( int i=0; i<5; i++ )
		cin >> a[i].W >> a[i].H;
	sort(a,a+5,cmp);
	cout<<"sort\n";
	for ( doll i : a )
		cout<<i.W<<' '<<i.H<<'\n';
	return 0;
}
