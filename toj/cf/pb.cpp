#include <bits/stdc++.h>
using namespace std;
bool strange(string s) {
	bool one=0;
	for (int i=0; i<s.size(); i++) {
		if (s[i]!='1' || s[i]!='0') return 0;
		if (one && s[i]=='1') return 0;
		if (s[i]=='1') one=1;
	}
	return 1;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	string s,t;
	cin >> n;
	while (n--) {
		cin>>s;
		if (strange(s)) t=s;
		else k+=s.size()-1;
	}
	cout<<t;
	for (int i=0; i<k; i++) cout<<"0";
	cout<<endl;
	return 0;
}

