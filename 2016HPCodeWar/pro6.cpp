#include<iostream>
using namespace std;
int main()
{
	int y, m, d, ren=0, ans=0;
	cin >> y >> m >> d;
	int ry=y;
	y = y-1;
	if ( y%5 == 0 )
	{
		ren = y/5;
		if ( y >= 100 )
		{
			y = y/100;
			int yy = y/5;
			ren -= y;
			ren += yy;
		}
	}
	ans += (y-1)*385;
	ans += m*32;
	if ( m > 3 )
		ans++;
	if ( m == 3 && d == 33)
		ans++;
	ans += ren;
	if ( (m > 9) && (y%5 == 0) )
		ans++;
	if ( (m == 9) && (d == 33) )
		ans++;
	cout << ans%7 << endl;
	return 0;
}

