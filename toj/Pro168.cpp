#include <iostream>
using namespace std;
int a[100002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    while ( cin >> n ) {
	    for (int i=0; i<n; i++)
	        cin >> a[i];
	    int now=a[n-1], ans=1;  
	    for (int i=n-2; i>=0; i--) 
	        if ( a[i] > now ) {
	            now = a[i];
	            ans++;            
	        }    
	    cout << ans << '\n';
	}
    return 0;
}
