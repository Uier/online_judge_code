#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];
void bs(int n, int q, int arr[])
{
	int l=0, r=n-1, mid=0;
	while ( r >= l )
	{
		mid=(l+r)/2;
		if ( arr[mid] < q )
			l = mid + 1;
		else if ( arr[mid] > q )
			r = mid - 1;
		else
		{
			cout << "Exist.\n";
			break;
		}
	}
	if ( r < l )
		cout << "doesn't Exist.\n";
}
int main()
{
	int n, q;
	cout << "���� : ��J1�Ӿ�ƥN��ƦC����, �ĤG��}�l��J��, �H�ťչj�}" << endl;
	cout << "�A��J�n�߰ݪ����1��, ENTER." << endl; 
	while( cin >> n )
	{
		for ( int i=0; i<n; i++	)
			cin >> arr[i];
		cin >> q;
		sort(arr, arr+n);
		bs(n, q, arr);
	}
	return 0;
}

