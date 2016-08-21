#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string> 
using namespace std;
string RanStrGen(int length) {
	string alphanum =
	"0123456789"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";
	string s;
	for ( int i=0; i<length; i++ )
		s.push_back(alphanum.at(char(rand()%alphanum.size())));
	return s;
}
int main()
{
//  strings consist of alpha-numeric chars.
//  call function with a integer which means strlen.
	srand(time(NULL));
	for ( int i=0; i<10; i++ )
		cout << RanStrGen(20) << endl;
	return 0;
}

