#include <iostream>
#include <cmath>
#define int long long
using namespace std;
int arr[2000];
main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int k,l,r;
	cin>>l>>r>>k;
	arr[0]=1;
	bool f=0;
	for (int i=1; i<=log(r)/log(k)+1; i++) {
		if (arr[i-1] > r/k+10) break;
		arr[i]=arr[i-1]*k;
	}
	for (int i=0; i<=log(r)/log(k)+1; i++) {
		if (arr[i]>=l && arr[i]<=r)  {
			cout<<arr[i]<<" ";
			f=1;
		}
	}
	if (!f) cout<<"-1";
	cout<<endl;
	return 0;
}

