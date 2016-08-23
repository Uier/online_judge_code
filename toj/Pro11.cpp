#include <iostream>
using namespace std;
int arr[2000005], st[2000005];
long long p=0;
void merge(int l, int r, int arr[])
{
    if ( l == r )
        return;
    int m=(l+r)/2;
    merge(l, m, arr);
    merge(m+1, r, arr);
    int lm=l, rm=m+1, k=l;
    while ( (lm < m+1) || (rm <= r) )
    {
        if ( (lm < m+1) && (rm <= r) )
        {
            if ( arr[lm] <= arr[rm] )
                st[k++] = arr[lm++];
            else
            {
                st[k++] = arr[rm++];
                p += rm - k;
            }
        }
        else if ( lm < m+1 )
            st[k++] = arr[lm++];
        else if ( rm <= r )
            st[k++] = arr[rm++];
    }
    for ( int j=l; j<=r; j++ )
        arr[j] = st[j];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for ( int i=0; i<n; i++ )
		cin >> arr[i];
	merge(0,n-1,arr);
	cout << p << '\n';
	return 0;
}

