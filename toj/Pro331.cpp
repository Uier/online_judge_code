#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int za=0, zb=0;
	string sa, sb;
	cin >> sa >> sb;
	for (int i = 0; i < sa.size(); ++i)
		if ( sa[i] == '0' )
			za++;
	for (int i = 0; i < sb.size(); ++i)
		if ( sb[i] == '0' )
			zb++;
	long long ans=(sa.size()-za)*(sb.size()-zb);
	cout << ans << endl;
	return 0;
}