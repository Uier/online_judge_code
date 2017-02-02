#include <iostream>
#include <string.h>
using namespace std;
int dp[50000001];
char s[50000001];
int main() {
	while ( ~scanf("%s", &s) ) {
		int L = strlen(s);
		dp[0] = 0;
		for ( int i=1, j=0; i<L; i++ ) {
			while ( j > 0 && s[i] != s[j] )	j = dp[j-1];
			if ( s[i] == s[j] )	j++;
			dp[i] = j;
		}
		int ans = L-dp[L-1];
		if ( L%ans )	printf("%s", s);
		else
			for ( int i=0; i<ans; i++ )
				printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}

