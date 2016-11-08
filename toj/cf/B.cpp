#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull get_gcd(ull a,ull b){
	if(a<b) swap(a,b);
	while(b){
		swap(a,b);
		b%=a;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ull t,a,b;
	cin>>t>>a>>b;
	if(a==b){
		cout<<"1/1\n";
	}else{
		ull x=min(a,b);
		
	}
	return 0;
}

