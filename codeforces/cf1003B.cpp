#include <iostream>
using namespace std;
int arr[300];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, x;
	cin >> a >> b >> x;
	int c = a+b;
	if ( a >= b ) {
		if ( x%2 ) {
			arr[0] = 1;
			b--;
		}
		int mid = x/2;
		for ( int i=c-2; i>0; --i ) {
			if ( mid == 0 )	break;
			if ( arr[i-1] == 0 && arr[i] == 0 && arr[i+1] == 0 ) {
				if ( mid == 1 ) {
					while ( b-- ) {
						arr[i] = 1;
						i--;
					}
					break;
				}
				arr[i] = 1;
				mid--;
				b--;
			}
		}
		int pt = (x%2==1 ? 1 : 0);
		for ( int i=0; i<b; ++i ) {
			arr[pt] = 1;
			pt++;
		}
	} else {
		for ( int i=0; i<c; ++i )	arr[i] = 1;
		if ( x%2 ) {
			arr[0] = 0;
			a--;
		}
		int mid = x/2;
		for ( int i=c-2; i>0; --i ) {
			if ( mid == 0 )	break;
			if ( arr[i-1] == 1 && arr[i] == 1 && arr[i+1] == 1 ) {
				if ( mid == 1 ) {
					while ( a-- ) {
						arr[i] = 0;
						i--;
					}
					break;
				}
				arr[i] = 0;
				mid--;
				a--;
			}
		}
		int pt = (x%2==1 ? 1 : 0);
		for ( int i=0; i<a; ++i ) {
			arr[pt] = 0;
			pt++;
		}
	}
	for ( int i=0; i<c; ++i )
		cout << arr[i];
	cout << '\n';
//	if ( a >= b ) {
//		int p = x-b;
//		int q = b-p;
//		if ( q == 1 )
//			arr[0] = 1;
//		else if ( q == 2 )
//			arr[c-1] = 1;
//		for ( int i=0; i<p; ++i ) {
//			for ( int j=1; j<c-1; ++j ) {
//				if ( arr[j-1] == 0 && arr[j] == 0 && arr[j+1] == 0 )
//					arr[j] = 1;
//			}
//		}
//	} else {
//		for ( int i=0; i<c; ++i )	arr[i] = 1;
//		int p = x-a;
//		int q = a-p;
//		if ( q == 1 )
//			arr[0] = 0;
//		else if ( q == 2 )
//			arr[c-1] == 0;
//		for ( int i=0; i<p; ++i ) {
//			for ( int j=1; j<c-1; ++j ) {
//				if ( arr[j-1] == 1 && arr[j] == 1 && arr[j+1] == 1 )
//					arr[j] = 0;
//			}
//		}
//	}
//	for ( int i=0; i<c; ++i )
//		cout << arr[i];
//	cout << '\n';
	return 0;
}

