#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double sum=0;
	priority_queue<double> pq;
	scanf("%d", &n);
	while ( n-- )
	{
		char c;
		double a;
		cin >> c >> a;
		pq.push(-a);
	}
	while ( pq.size() > 1 )
	{
		double a, b;
		a = pq.top();	pq.pop();
		b = pq.top();	pq.pop();
		sum += a+b;
		pq.push(a+b);
	}
	printf("%.2lf\n", -sum);
	return 0;
}

