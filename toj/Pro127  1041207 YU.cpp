#include<iostream>
using namespace std;
int main()
{
	int n,len;
	string pw;
	cin >> n >> pw;
	len = pw.size();
	int npw[len];
	for ( int i=0; i<len; i++ ) {
		if ( int(pw[i]) >= 65+n ) {
			npw[i] = pw[i] - n;
		}
		else {
			npw[i] = pw[i] - n + 26;
		}
	}
	for ( int j=0; j<len; j++ ) {
		cout << char(npw[j]);
	}
	cout << endl; 
	return 0;
}

