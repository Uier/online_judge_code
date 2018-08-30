#include <iostream> 
#define maxn 2000005
using namespace std;
int arr[maxn], tmp[maxn];
long long ans = 0;
void merge_sort(int l, int r) {
    if ( l == r )    return;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int pt = l, ptl = l, ptr = mid+1;
    while ( pt <= r )
        if ( ptl <= mid && (arr[ptl] <= arr[ptr] || ptr > r) )
            tmp[pt++] = arr[ptl++];
        else {
            ans += ptr-pt;
            tmp[pt++] = arr[ptr++];
        }
    for ( int i=l; i<=r; ++i )    arr[i] = tmp[i];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for ( int i=1; i<=n; ++i )    cin >> arr[i];
    merge_sort(1,n);
    cout << ans << '\n';
    return 0;
}
