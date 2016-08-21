#include<bits/stdc++.h>
using namespace std;
struct lct{
	double x, y;
} ac[1000003];
int main()
{
	int n, i=0;
	double min;
	scanf("%d", &n); 
	while ( n-- )
	{
		scanf("%lf %lf", &ac[i].x, &ac[i].y);
		if ( i > 1 )
		{
			for ( int j=0; j<i; j++ )
			{
				if ( sqrt((ac[i].x-ac[j].x)*(ac[i].x-ac[j].x)+(ac[i].y-ac[j].y)*(ac[i].y-ac[j].y)) < min )
					min = sqrt((ac[i].x-ac[j].x)*(ac[i].x-ac[j].x)+(ac[i].y-ac[j].y)*(ac[i].y-ac[j].y));
			}
		}
		else if ( i == 1 )
			min = sqrt((ac[i].x-ac[i-1].x)*(ac[i].x-ac[i-1].x)+(ac[i].y-ac[i-1].y)*(ac[i].y-ac[i-1].y));
		i++;
	}
	printf("%.6lf\n", min);
	return 0;
}

