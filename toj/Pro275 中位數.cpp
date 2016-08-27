#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n;
	double a;
 	scanf("%d %lf", &n, &a);
	printf("%.6lf\n", a);
	multiset<double> s;
	s.insert(a);
	auto i=s.begin(), j=s.begin();
	while ( --n ) {
		scanf("%lf", &a);
		s.insert(a);
		if ( *i >= a ) {
			if ( n%2 == 1 )
				i--;
			else
				j--;
		}
		else if ( *j <= a ) {
			if ( n%2 == 1 )
				j++;
			else
				i++;	
		}
		else {
			i++;
			j--;
		}
		printf("%.6lf\n", (*i+*j)/2);
	}
	return 0;
}

