#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define maxn 100005
using namespace std;
int n, cnt[200], mod = 1e9+7, arr[52], vis[52], ans, f[maxn];
vector<int> tmp;
int _pow(int a, int b) {
	int powans = 1, base = a;
	while ( b ) {
		if ( b&1 )	powans *= base;
		base *= base;
		base %= mod;
		powans %= mod;
		b >>= 1;
	}
	return powans;
}
void dfs(int val, int l, int d1, int d2) {
	if ( val == 0 ) {
		int anstmp = f[n/2];
		for ( int i : tmp )
			anstmp = anstmp*_pow(f[i],mod-2)%mod;
//		cout << "anstmp: " << anstmp << '\n';
		int leftmp = f[n/2];
		for ( int i=0; i<52; ++i )
			if ( arr[i] > 0 && vis[i] == 0 )
				leftmp = leftmp*_pow(f[arr[i]],mod-2)%mod;
		leftmp = leftmp*_pow(f[d1],mod-2)%mod;
		leftmp = leftmp*_pow(f[d2],mod-2)%mod;
		ans = (ans+anstmp*leftmp)%mod;
		return;
	}
	for ( int i=l; i<52; ++i ) {
		if ( arr[i] > 0 && val >= arr[i] && vis[i] != 2 ) {
			vis[i] = 1;
			tmp.emplace_back(arr[i]);
			dfs(val-arr[i],i+1,d1,d2);
			vis[i] = 0;
			tmp.pop_back();
		}
	}
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, a, b;
	string s;
	cin >> s >> q;
	n = s.size();
	f[0] = 1;
	for ( int i=1; i<=n; ++i )	f[i] = f[i-1]*i%mod;
	for ( int i=0; i<n; ++i ) {
		cnt[s[i]]++;
		if ( s[i] <= 'Z' )	arr[s[i]-'A']++;
		else	arr[s[i]-'a'+26]++;
	}
	while ( q-- && cin >> a >> b ) {
		a--;	b--;
		ans = 0;
		if ( s[a] == s[b] )	{
			if ( cnt[s[a]] > n/2 )	cout << 0 << '\n';
			else {
				int sum = n-cnt[s[a]];
				if ( s[a] <= 'Z' )	vis[s[a]-'A'] = 2;
				else	vis[s[a]-'a'+26] = 2;
				dfs(n/2,0,cnt[s[a]],1);
				if ( s[a] <= 'Z' )	vis[s[a]-'A'] = 0;
				else	vis[s[a]-'a'+26] = 0;
				cout << (ans*2)%mod << '\n';
			}
		} else {
			if ( cnt[s[a]]+cnt[s[b]] > n/2 )	cout << 0 << '\n';
			else {
				int sum = n-cnt[s[a]]-cnt[s[b]];
				if ( s[a] <= 'Z' )	vis[s[a]-'A'] = 2;
				else	vis[s[a]-'a'+26] = 2;
				if ( s[b] <= 'Z' )	vis[s[b]-'A'] = 2;
				else	vis[s[b]-'a'+26] = 2;
				dfs(n/2,0,cnt[s[a]],cnt[s[b]]);
				if ( s[a] <= 'Z' )	vis[s[a]-'A'] = 0;
				else	vis[s[a]-'a'+26] = 0;
				if ( s[b] <= 'Z' )	vis[s[b]-'A'] = 0;
				else	vis[s[b]-'a'+26] = 0;
				cout << (ans*2)%mod << '\n';
			}
		}
	}
	return 0;
}

