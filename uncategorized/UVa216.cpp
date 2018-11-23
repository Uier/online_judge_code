#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct node {
	int x, y;
} arr[10];
int n, cs = 1, path[10];
double ans = -1;
bool V[10];
vector<int> tmp;
int dist(node a, node b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void rec() {
	double s = 0;
	for ( int i=1; i<n; ++i )	s += sqrt(dist(arr[tmp[i-1]],arr[tmp[i]]));
	if ( ans == -1 || s < ans ) {
		ans = s;
		for ( int i=0; i<n; ++i )	path[i] = tmp[i];
	}
}
void dfs(int x) {
	if ( x == n ) {
		rec();
		return;
	}
	for ( int i=1; i<=n; ++i )
		if ( !V[i] ) {
			V[i] = true;
			tmp.emplace_back(i);
			dfs(x+1);
			V[i] = false;
			tmp.pop_back();
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin >> n && n ) {
		ans = -1;
		tmp.clear();
		for ( int i=1; i<=n; ++i )	cin >> arr[i].x >> arr[i].y;
		dfs(0);
		printf("**********************************************************\n");
		printf("Network #%d\n", cs++);
		double sum = 0;
		for ( int i=1; i<n; ++i ) {
			double dis = sqrt(dist(arr[path[i-1]],arr[path[i]]))+16;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", arr[path[i-1]].x, arr[path[i-1]].y, arr[path[i]].x, arr[path[i]].y, dis);
			sum += dis;
		}
		printf("Number of feet of cable required is %.2lf.\n", sum);
	}
	return 0;
}

