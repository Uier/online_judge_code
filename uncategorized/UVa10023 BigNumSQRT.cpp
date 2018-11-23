#include <iostream>
#include <vector>
#include <string.h>
#define maxn 1005
using namespace std;
vector<int> ans;
inline bool check(int a[], int b[], int add, int lim) {
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, len = 0, arr[maxn], brr[maxn];
	string s;
	cin >> t;
	while ( t-- && cin >> s ) {
		memset(arr,0,sizeof(arr));
		memset(brr,0,sizeof(brr));
		ans.clear();
		len = s.size();	
		for ( int i=0, j=len-1; j>=0; ++i, j-=2 )
			if ( j-1 >= 0 )	arr[i] = (s[j-1]-'0')*10+(s[j]-'0');
			else	arr[i] = (s[j]-'0');
		for ( int i=0; i<len; ++i ) {
			int x = 9;
			for ( ; x>=0; x-- )
				if ( check() )
					break;
			
		}
		
	}
	return 0;
}

