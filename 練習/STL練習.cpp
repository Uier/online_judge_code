#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<set>
// why can not struct do string?
struct stu{
	int id;
	string name;
};

bool operator < (const stu &a, const stu &b)
{
	return a.id < b.id;
}
//	定義新結構(struct)的'<'的定義
//	因LINE26 SET要比較大小 

using namespace std;
int main()
{
	stu a, b;
	a.id = 5;
	a.name = "jj";
	b.id = 7;
	b.name = "hh";
	set<stu> v;
	v.insert(a);
	v.insert(b); 
	
  /*
########	V	E	C	T	O	R    ########
		
	int n;
	vector<int> a;
	while ( cin >> n )
	{
		if ( n == 0 )
			break;
		a.push_back(n);
	}
	cout << a.size() << endl;
	int m;
	cin >> m;
	cout << a[0] << ' ' << a.front() << ' ' << a.back() << endl;
	for ( int i=0; i<m; i++ )
		a.pop_back();
//  a.clear(); 清空 
	if ( a.empty() )
		cout << "empty" << endl;
	for ( int i : a )
		cout << i << ' ';
		
		*/
	/*	
	int n;
	cin >> n;
	int a[n];
	for ( int i : a )
		cin >> i;
	for ( int i : a )
		cout << i << ' ';
	system("pause");
	*/
	
	/*
	
		########	S	T	A	C	K	########
		
			如果STACK是空的 無法 .top() 及 .pop() 
		 
	int k=1;
	stack<int> s;
	s.push(k);
	k++;
	s.push(k);
	k++;
	s.push(k);
	int i=3;
	while ( i-- )
		s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	
	*/
	/*	
	
		#########	S	E	T	########
		
			set內之元素不能重複, 而multiset會保留. 
	
	set<int> s;
	s.insert(19);
	s.insert(2);
	s.insert(10);
	
	for ( int i : s )
		cout << i << ' ';
	cout << endl;
	
	int n=*s.find(2);
	
	cout << n << endl;
	
	cout << *s.begin() << ' ' << *s.rbegin() << endl;
	
	cout << *s.end() << endl;
	
	s.find() -> 若沒找到, 會返回s.end();
	故
	if ( s.find(2) != s.end() )
		cout << "Find 2!" << endl;
	else
		cout << "Not exist" << endl; 
	
	*/
	
	return 0;
}

