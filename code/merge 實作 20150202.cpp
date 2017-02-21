#include<iostream>
using namespace std;
int arr[500050], st[500050];
long long totm=0;
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
				totm += rm - k;
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
	int n;
	while(cin >> n)
	{
		if ( n == 0 )
            break;
		for ( int i=0; i<n; i++ )
			cin >> arr[i];
		totm=0;
		merge(0, n-1, arr);
	//	for ( int i=0; i<n; i++ )
	//		cout << arr[i] << ' ';
	//	cout << endl;
		cout << totm << endl;
	}
	return 0;
}

