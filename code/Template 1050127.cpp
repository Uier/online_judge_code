#include<iostream>
#include<bits/stdc++.h>
#include<numeric>
using namespace std;

template <typename T>
T abs(T i)
{
	if ( i >= 0 )
		return i;
	return -i;
}

int main()
{
	//c++11 lambda
	int a[5]={1,5,2,3,4};
	vector<int> v{6,5,3,4,80};
	sort(a,a+5);
	sort(v.begin(),v.end());
	cout << "SORT a[], v(vector<int>) : " << endl;
	for ( int i : a )
		cout << i << ' ';
	cout << endl;
	for ( int i : v )
		cout << i << ' ';
	cout << endl; 
	// lower_bound >= K
	// upper_nound > K
	cout << "lower , lower記憶體位置(指標相減)" << endl; 
	cout << *lower_bound(v.begin(),v.end(),50) << endl; // -v.begin()  ??
	cout << lower_bound(v.begin(),v.end(),6)-v.begin() << endl;
	cout << "upper , upper記憶體位置(指標相減)" << endl;
	cout << *upper_bound(v.begin(),v.end(),6) << endl;
	cout << upper_bound(v.begin(),v.end(),6)-v.begin() << endl;
	
	cout << "min , min記憶體位置(指標相減)" << endl;
	
	cout << *min_element(a,a+5) << endl;
	cout << min_element(a,a+5)-a << endl;
	
	cout << "max , max記憶體位置(指標相減)" << endl;
	
	cout << *max_element(a,a+5) << endl;
	cout << max_element(a,a+5)-a << endl;
	
	int b[4] = {9,8,7,6};
	do{
		for ( int i : b )
			cout << i << ' ';
		cout << endl;
	}while( next_permutation(b,b+4) );
	
	int c[6] = {2,5,4,5,4,3};
	cout << count(c,c+6,5) << endl; // 陣列A~A+7中有幾個5
	reverse(c,c+6);
	for ( int i : c )
		cout << i << ' ';
	cout << endl;
	replace(c,c+6,5,10);
	for ( int i : c )
		cout << i << ' ';
	cout << endl;
	
	int d[]={1,2,3,5,5,5,4};
	partial_sum(a,a+7,a);
	for ( int i : d )
		cout << i << ' ';
	cout << endl;
	// #<numeric>
	
//	x[]
//	y[]
//	inner_product(x,x+?,y,0)


	
	set<int> s; // multiset可存多個一樣的值 
	s.insert(15);
	s.insert(16);
	s.insert(2);
	s.insert(8);
	
	map<string,int> mp;
	mp["256"] = 256; 
	
	cout << mp["666"] << ' ' << mp["256"] << endl;
	if ( mp.find("666") != mp.end() )
		cout << mp["666"] << endl;
	else
		cout << "ERROR!" << endl;
	
	cout << *s.begin() << endl;
	cout << *s.rbegin() << endl;
	s.erase(15); 
	for ( int i : s )
		cout << i << ' ';
//	cout << abs << endl;
	cout << abs<double>(-5.55) << endl;
	// <int> <double> 可省
// -----------------------
	cout << "priority_queue" << endl; 
	priority_queue<int> pq;
	pq.push(5);
	pq.push(3);
	pq.push(6);
	// pq.pop() 刪掉最大 
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
// -----------------------
// 		push_______
//		    0    left(*2+1) right(*2+2)
//		1       2
//	  3   4   5   6
// 		a
//    b   c
//		須滿足a>b,a>c else swap
// -----------------------
	//priority_queue( int, vectore<int>, less<int> > mn;
	//priority_queue( int, vectore<int>, greater<int> > mn;
	return 0;
}

