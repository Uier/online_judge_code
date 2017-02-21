#include<bits/stdc++.h>
using namespace std;
int main()
{
	priority_queue<int> pq_big;
	
	priority_queue<int,vector<int>,greater<int> > pq_sml;
	
	for ( int i=0; i<3; i++ ) {
		int x;
		cin >> x;
		pq_big.push(x);
		pq_sml.push(x);
	}
	
	cout << "big: " << pq_big.top();	pq_big.pop();
	cout << '\n' << pq_big.top() << '\n';
	
	cout << "sml: " << pq_sml.top();	pq_sml.pop();
	cout << '\n' << pq_sml.top() << '\n';
		
	
	return 0;
}

