#include<iostream>
using namespace std;
#define max 1000000
bool notprm[max]={0};
int prm[500];
bool prime(int n, int a)
{
	bool flag=false;
	if ( n > 1000 )
	{
		for ( int i=0; i<a; i++ )
		{
			if ( n%prm[i] == 0 )
				return false;
		}
		return true;
	}
	else
	{
		if ( notprm[n] )
			return false;
		return true;
	}
}
int main()
{
	int b=0;
	notprm[0] = notprm[1] = true;
	for ( int i=2; i<=1000; i++ )
	{
		if ( !notprm[i] )
		{
			prm[b++] = i;
			for ( int j=i*i; j<=1000; j+=i )
				notprm[j] = true;
		}
	}
	string s;
	while ( cin >> s )
	{
		int q=0, time=1;
		for ( int a=0; a<s.size(); a++ )
		{
			for ( int b=1; b<s.size()-a; b++ )
				time *= 10;
			q += (s[a]-'0')*time;
			time = 1;
		}
		if ( prime(q, b) )
		{
			int af=0, c=0;
			for ( int a=s.size()-1; a>=0; a--, c++ )
			{
				for ( int b=1; b<s.size()-c; b++ )
					time *= 10;
				af += (s[a]-'0')*time;
				time = 1;
			}
			if ( (prime(af, b)) && (af != q) )
				cout << q << " is emirp." << endl;
			else
				cout << q << " is prime." << endl;
		}
		else
			cout << q << " is not prime." << endl;
	}
	return 0;
}

