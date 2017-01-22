#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int number[9], number2[8], number3[8], SSum = 0;
bool flag;
int fun1(char a,char b,char c,int ptr)
{
	char arr[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	int B = 0,O = 0,X = 0;
	for(int i = 0;i < 3;i++)
	{
		if(arr[i] == 'B')
			B++;
		if(arr[i] == 'O')
			O++;
		if(arr[i] == 'X')
			X++;
	}
	//cout << "ejifowjwejo" << ptr - 1 << endl;
	if(B == 3)
		return number3[ptr - 1];
	
	if(flag)
		swap(O, X);

	int sum = 0;
	if(O == 1)
		sum += number2[1];
	if(O == 2)
		sum += number2[2];
	if(O == 3)
		sum += number2[3];
	if(X == 1)
		sum += number2[5];
	if(X == 2)
		sum += number2[6];
	if(X == 3)
		sum += number2[7];
	if(X == 0)
		sum += number2[4];
	if(X + O == 3)
		return 0;

	return sum;
	
}
int main()
{
	fstream filein;
	filein.open("a.txt",fstream::in);
	
	cin >> number[0];
	for(int i = 1;i < 9;i++)
	{
		string s;
		getline(cin, s,',');
		cin >> number[i];
	}
	number3[0] = number[0] + number[1] + number[2];
	number3[1] = number[3] + number[4] + number[5];
	number3[2] = number[6] + number[7] + number[8];
	number3[3] = number[0] + number[3] + number[6];
	number3[4] = number[1] + number[4] + number[7];
	number3[5] = number[2] + number[5] + number[8];
	number3[6] = number[0] + number[4] + number[8];
	number3[7] = number[2] + number[4] + number[6];
	cin >> number2[0];
	for(int i = 1;i < 8;i++)
	{
		string s;
		getline(cin, s,',');
		cin >> number2[i];
	}
	
	string s;
	getline(cin ,s);
	while(getline(cin, s))
	{
		flag = 0;
		
		int wsum = 0;
		if(s.length() != 9)
			break;
			
		int OO = 0,XX = 0;
		for(int j = 0;j < 9;j++)
		{
		
			if(s[j] == 'O')
				OO++;
			if(s[j] == 'X')
				XX++;
		}
		if(OO != XX)
			flag = 1;
			
			
		wsum += fun1(s[0], s[1], s[2], 1);
		cout << wsum << endl;
		wsum += fun1(s[3], s[4], s[5], 2);
		cout << wsum << endl;
		wsum += fun1(s[6], s[7], s[8], 3);
		cout << wsum << endl;
		wsum += fun1(s[0], s[3], s[6], 4);
		cout << wsum << endl;
		wsum += fun1(s[1], s[4], s[7], 5);
		cout << wsum << endl;
		wsum += fun1(s[2], s[5], s[8], 6);
		cout << wsum << endl;
		wsum += fun1(s[0], s[4], s[8], 7);
		cout << wsum << endl;
		wsum += fun1(s[2], s[4], s[6], 8);
		cout << wsum << endl;
		SSum += wsum;
	}
	cout << SSum << endl; 
	/*
	for(int i = 0;i < 8;i++)
		cout << number2[i];
	*/
	return 0;
}

