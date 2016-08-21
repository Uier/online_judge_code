#include<iostream>
using namespace std;
int main()
{
	long long a;
	long long m,b,n;
	char c;
	cin >> a >> m >> b;
	a = a%b;
	for (int i=0;i<m;i++)
	{
		cin >> n >> c;
		a = a * (n%b);
		a = a%b;
	}
	cout << a%b << endl;
	return 0;
}
