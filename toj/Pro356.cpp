#include <iostream>
using namespace std;
int a[1024*8][1024*8];
void fillup(int x1, int y1, int x2, int y2, int s, int d) {
	int p=1;
	while ( d-- )
		p *= 4;
	a[x1][y1] = s;
	a[x2][y2] = s+p;
	a[x1][y2] = s+p+p;
	a[x2][y1] = s+p+p+p;
}
void depth(int x1, int y1, int x2, int y2, int s, int dep) {
	if ( y2 - y1 == 1 )
		fillup(x1,y1,x2,y2,s,dep);
	else {
		int pd=dep, bs=1;
		while ( pd-- )
			bs *= 4;
		depth(x1,y1,(x1+x2)/2,(y1+y2)/2,s,dep+1);
		depth((x1+x2)/2+1,(y1+y2)/2+1,x2,y2,s+bs,dep+1);
		depth(x1,(y1+y2)/2+1,(x1+x2)/2,y2,s+bs*2,dep+1);
		depth((x1+x2)/2+1,y1,x2,(y1+y2)/2,s+bs*3,dep+1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m=1;
	scanf("%d", &n); 
	if ( n == 0 )
		printf("1\n");
	else {
		while ( n-- )
			m *= 2;
		int x1=0, y1=0, x2=m-1, y2=m-1;
		depth(x1,y1,x2,y2,1,0);
		for ( int i=0; i<m; i++ ) {
			for ( int j=0; j<m; j++ )
				cout << a[i][j] << ' ';	
			cout << '\n';
		}
	}
	return 0;
}

