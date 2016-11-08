#include <bits/stdc++.h>
#define double long double
using namespace std;
struct Point {
	double x,y;
} poly[100005];
double dis(Point p, Point q) {
	return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}
double PI = acos(-1);
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	Point P,a;
	double maxdis=-1,mindis=1e9;
	cin >> n >>P.x>>P.y;
	while (n--) {
		cin>>a.x>>a.y;
		maxdis=max(maxdis,dis(a,P));
		mindis=min(mindis,dis(a,P));
	};
	cout<<fixed<<setprecision(20)<<(PI*maxdis*maxdis - PI*mindis*mindis)<<endl;
	return 0;
}

